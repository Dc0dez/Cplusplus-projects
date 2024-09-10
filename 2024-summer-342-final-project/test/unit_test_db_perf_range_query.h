#include "gtest/gtest.h"
#include "btree/map.h"
#include "db_index/hash_map_index.h"
#include "unit_test_db_perf_common.h"

long long run_range_query_test(GasWorksDB &db,
                               unsigned age_lower_bound,
                               unsigned age_upper_bound,
                               bool db_support_range_query,
                               std::vector<Record> &found_record) {
    auto start = high_resolution_clock::now();

    if (db_support_range_query) {
        db.find_by_age_range(age_lower_bound, age_upper_bound, found_record);
    } else {
        for (unsigned age = age_lower_bound; age <= age_upper_bound; age++) {
            db.find_by_age(age, found_record);

//            std::vector<Record> found_records_by_age;
//            db.find_by_age(age, found_records_by_age);

            /*
             *  The loop is only necessary if using the vector 'std::vector<Record> found_records_by_age;'
             *  In this case, the range query test will fail without the loop
             *
             *  However, using the aforementioned loop and vector results in unnecessary memory copying
             *  and significantly slows down the efficiency of storing values in the found_record vector that are located by the range query search using hash index
             *
             *  To increase efficiency and reduce unnecessary memory copies, I changed 'db.find_by_age(age, found_records_by_age);' to 'db.find_by_age(age, found_record);'
             *
             *  Using the following test parameters:
             *  MAX_TABLE_SIZE = 35,000, STEP_TABLE_SIZE = 1000, age_lower_bound = 50, and age_upper_bound = 58
             *
             *  Performance without change:
             *  35000,10176,5059,5262
             *
             *  Performance with change:
             *  35000,4549,4505,4779
             *
             *  Without the change, the amount of time the range query takes for 35,000 records using hash index is 10176 microseconds
             *  With the change, the amount of time the range query takes for 35,000 records using hash index is 4549 microseconds
             *  This demonstrates that the change cuts the time for the range query using hash index in half, and it also improves the performance of the query using b_tree index and direct search
             */

//            for (auto &record: found_records_by_age) {
//                found_record.push_back(record);
//            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

void run_index_perf_range_query(unsigned table_size,
                                unsigned MIN_HOBBY_COUNT,
                                unsigned HOBBY_TYPE_COUNT,
                                unsigned AGE_MAX) {
    if (table_size == 0) {
        return;
    }

    /*
     * create a hash indexed db and a btree indexed db
     */
    GasWorksDB hash_indexed_db(new HashIndexGroup());
    hash_indexed_db.set_enable_index(true);

    GasWorksDB btree_indexed_db(new BtreeIndexGroup());
    btree_indexed_db.set_enable_index(true);

    /*
     * insert records
     */
    std::vector<Record *> records;
    prepare_db_for_perf_test(hash_indexed_db,
                             btree_indexed_db,
                             table_size, HOBBY_TYPE_COUNT, MIN_HOBBY_COUNT, AGE_MAX, records);

    unsigned age_lower_bound = 50;
    unsigned age_upper_bound = 52;

    /*
     * test search using hash indexed db
     */
    std::vector<Record> found_records_hash_index;
    auto hash_index_time = run_range_query_test(hash_indexed_db,
                                                age_lower_bound,
                                                age_upper_bound,
                                                false,
                                                found_records_hash_index);

    /*
     * test search using btree indexed db
     */
    std::vector<Record> found_records_btree_index;
    auto btree_index_time = run_range_query_test(btree_indexed_db,
                                                 age_lower_bound,
                                                 age_upper_bound,
                                                 true,
                                                 found_records_btree_index);

    /*
     * test search without index
     */
    std::vector<Record> found_records_no_index;
    btree_indexed_db.set_enable_index(false);    // disable index
    auto no_index_time = run_range_query_test(btree_indexed_db,
                                              age_lower_bound,
                                              age_upper_bound,
                                              true,
                                              found_records_no_index);

    /*
     * validate consistent search results regardless of db
     */
    ASSERT_TRUE(!found_records_no_index.empty());
    ASSERT_TRUE(!found_records_hash_index.empty());
    ASSERT_TRUE(!found_records_btree_index.empty());

    ASSERT_EQ(found_records_no_index.size(), found_records_hash_index.size());
    ASSERT_EQ(found_records_no_index.size(), found_records_btree_index.size());

    std::set<unsigned> btree_index_ids;
    for (auto &record: found_records_btree_index) {
        btree_index_ids.insert(record.get_id());
    }

    std::set<unsigned> btree_unindex_ids;
    for (auto &record: found_records_no_index) {
        btree_unindex_ids.insert(record.get_id());
    }

    std::set<unsigned> hash_index_ids;
    for (auto &record: found_records_hash_index) {
        hash_index_ids.insert(record.get_id());
    }

    ASSERT_EQ(hash_index_ids, btree_index_ids);
    ASSERT_EQ(hash_index_ids, btree_unindex_ids);

    /*
     * print out times
     */
    std::cout << table_size << ","
              << hash_index_time
              << ","
              << btree_index_time
              << ","
              << no_index_time
              << std::endl;

    for (auto record : records) {
        delete record;
    }
}