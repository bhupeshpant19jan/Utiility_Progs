#ifndef _JOB_REF_TREE_H
#define _JOB_REF_TREE_H


#include <iostream>
#include <algorithm>
#include <map>
#include <list>

struct job_info{
    int id;
    int start_time;
    int end_time;
};

//struct job_ref{
//    job_info job;
//    job_info* next_job;
//};

class JobRefTree{

public:
    void parse_job_table(std::map<int, job_info*> job_table);
    int get_max_job_added();
private:
    bool check_if_job_can_be_accomodated(std::list<job_info*> job_ref, job_info* job_info_o);

    std::list<job_info*> job_node;
    std::list<std::list<job_info*>> job_tree;
    
};

#endif //