#include <bits/stdc++.h>
#include <sys/time.h>
#include <iostream>
#include <fstream>
#include "db.h"   
#include "leveldb/filter_policy.h"
#include "leveldb/env.h"
#define MAXN 112345
//#define CHECK_INPUT

using namespace std;

char st[MAXN];

void dbDelete(string key) {
    struct timespec ts;
    //clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    double last_time_ = static_cast<int64_t>(ts.tv_sec) * 1000000000Lu + static_cast<int64_t>(ts.tv_nsec);
    

    double current_time_ = static_cast<int64_t>(ts.tv_sec) * 1000000000Lu + static_cast<int64_t>(ts.tv_nsec);
    double latency = current_time_ - last_time_;

    // handle latency for delete
    
}

void dbRead(string key) {
    
}

void dbPut(string key, string value) {
}

void dbInsert(string key, string value) {
    
  
}

//#define CHECK_INPUT
ifstream infile;




int main( ) {
   
    
    leveldb::Options options;
    options.block_cache = NULL;
    options.filter_policy = leveldb::NewBloomFilterPolicy(8);
    options.max_open_files = 20000;
    options.create_if_missing = true;
    leveldb::DB* db;
    std::string dbpath = "tdb";   
    leveldb::Status status = leveldb::DB::Open(options, dbpath, &db);   
    leveldb::Status s ;  
    assert(status.ok());   
    printf("Open db OK\n");  
    
    struct timeval tvmain;
    double t_start, t_end, t_duration;
    time_t t;
    
     infile.open("../../dataset/load.txt");
    //FILE *fp = fopen("load", "r");
    
    string str,val;
    /*
    gettimeofday(&tvmain, NULL);
    t_start = (double)tvmain.tv_sec + (double)tvmain.tv_usec * 1e-6;
    */
    
    while (getline(infile, str)) {
       
        
        int pos = str.find(' ');
        string operation = str.substr(0, pos);
        str.erase(0, pos + 1);
        if (operation == "delete") {
           
	    s = db->Delete(leveldb::WriteOptions(),str);
	    
#ifdef CHECK_INPUT
            cout << str << endl;
#endif
        } else if (operation == "read") {
           
	   s = db->Get(leveldb::ReadOptions (), str, &val);  
	  
#ifdef CHECK_INPUT
            cout << str << " " << val << endl;
#endif
        } else {
            pos = str.find(' ');
            string key = str.substr(0, pos);
            str.erase(0, pos + 1);
            if (operation == "put") {
                s = db->Put(leveldb::WriteOptions(), key,str); 
            } else {
                s = db->Put(leveldb::WriteOptions(), key,str); 
            }
            
#ifdef CHECK_INPUT
            cout << key << " " << str << endl;
#endif
        }
    }
    
    infile.close();
    
    system("cp /home/weitao/bloomfilterTest/leveldb/Avenger/tdb/LOG /home/weitao/bloomfilterTest/log"); 
    
   // copy("/home/weitao/bloomfilterTest/tdb/log","/home/weitao/bloomfilterTest/log");
    
    /*
    gettimeofday(&tvmain, NULL);
    t_end = (double)tvmain.tv_sec + (double)tvmain.tv_usec * 1e-6;
    t_duration = t_end - t_start;

    printf("Get  : %0.6f\n ", t_duration);
    */
    //db->Get_time();
    
    
    //read key value
    infile.open("/home/weitao/bloomfilterTest/dataset/uread.txt");
    
    

    
    gettimeofday(&tvmain, NULL);
    t_start = (double)tvmain.tv_sec + (double)tvmain.tv_usec * 1e-6;
    
    
    
    while ( getline(infile, str) ) {
       
	
        
        int pos = str.find(' ');
        string operation = str.substr(0, pos);
        str.erase(0, pos + 1);
        if (operation == "delete") {
           
	    s = db->Delete(leveldb::WriteOptions(),str);
	    

        } else if (operation == "read") {
           
	   s = db->Get(leveldb::ReadOptions (), str, &val);  
	  

        } else {
            pos = str.find(' ');
            string key = str.substr(0, pos);
            str.erase(0, pos + 1);
            if (operation == "put") {
                s = db->Put(leveldb::WriteOptions(), key,str); 
            } else {
                s = db->Put(leveldb::WriteOptions(), key,str); 
            }
            

        }
    }
    
    infile.close();
    
    //CopyFile("e:\\abb.txt","d:\\zhengyong.txt",FALSE);
   
    
    //Log(options.info_log,  "..........................");
    
    gettimeofday(&tvmain, NULL);
    t_end = (double)tvmain.tv_sec + (double)tvmain.tv_usec * 1e-6;
    t_duration = t_end - t_start;

    
    
    printf("       %.3lf  time: \n", t_duration);
    
    
    delete db;
    
    return 0;
}
