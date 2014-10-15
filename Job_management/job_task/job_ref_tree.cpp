//#ifndef _JOB_REF_TREE_
//#define _JOB_REF_TREE_

#include "job_ref_tree.h"
#include<stdio.h>
#include <stdlib.h>

void JobRefTree::parse_job_table(std::map<int, job_info*> job_table){
    /*Read the table and create the table*/
    for (auto index:job_table){
        job_info* job_info_o = new job_info;
        job_info_o->start_time = index.second->start_time;
        job_info_o->end_time = index.second->end_time;
        job_info_o->id = index.second->id;
        
        std::list<job_info*> job_queue;
        job_queue.push_back(job_info_o);
        job_tree.push_back(job_queue);
        //if (true == job_tree.empty()){
        //    std::list<job_info*> job_queue;
        //    job_queue.push_back(job_info_o);
        //    job_tree.push_back(job_queue);
        //}
        //else{
            for (auto& i:job_tree){
                if(check_if_job_can_be_accomodated(i, job_info_o)){
                    i.push_back(job_info_o);
                }
        /*        else{
                    std::list<job_info*> job_queue;
                    job_queue.push_back(job_info_o);
                    job_tree.push_back(job_queue);            
                }*/

            }
        //}
    }
}

bool JobRefTree::check_if_job_can_be_accomodated(std::list<job_info*> job_ref, job_info* job_info_o){
    /**/
    bool status = true;
    for(auto node:job_ref){
        if (node->id == job_info_o->id) return false;
        auto start_time = node->start_time;
        auto end_time = node->end_time;
        /*(job_info_o->start_time > start_time && job_info_o->end_time > end_time) ||
            (job_info_o->start_time < start_time && job_info_o->end_time < start_time)*/
        /*if ((start_time > job_info_o->start_time && start_time >= job_info_o->end_time)||
            (end_time < job_info_o->start_time && end_time > job_info_o->end_time)){*/
        if((job_info_o->end_time > start_time && job_info_o->end_time < end_time)  ||
            (job_info_o->start_time > start_time && job_info_o->start_time< end_time) ||
            (job_info_o->start_time <= start_time && job_info_o->end_time >= end_time)){
                status=false;
        }
    }
    return status;
}


int JobRefTree::get_max_job_added(){
    /**/
    auto size = -1;
    for(auto index: job_tree){
        if(size < (int)index.size()){
            size = index.size();
        }
    }
    return size;
}
//#endif //_JOB_REF_TREE_