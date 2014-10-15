#include<stdio.h>
#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include"job_ref_tree.h"

std::vector<std::string> tokenize(std::string data_string, std::string delimiter = " "){
    /*Tokenize the string and return the vector<std::string>*/
    std::vector<std::string> tokens;
    data_string = data_string.substr(1, data_string.length() - 2);
    int next = -1, pre = 0;
    while(1){
        next = data_string.find(delimiter, pre);
        if (next == std::string::npos){
            if(pre > 0){
                tokens.push_back(data_string.substr(pre));
            }
            break;
        }
        tokens.push_back(data_string.substr(pre, next - pre));
        pre = next +1;
    }
    return tokens;
}

class JobSchduler{
public:
    /*JobSchduler();
    ~JobSchduler();
*/
    int ParseInput(std::string input){
        /*Parse the table and populate the job_table*/
        std::string delimiter = ",";
        std::vector<std::string> data_tokens= tokenize(input, delimiter);
        std::vector<job_info*> job_table;
        create_job_table(data_tokens);
        return 1;
    }
    
    void create_job_scheduler(){
        /*This function will read the job table and create a job tree */
        obj.parse_job_table(job_table);
        
    }
   
    int calculate_maximum_profit(){
        /*Calculate the profit based on the amount of work it will do*/
        auto task = obj.get_max_job_added();
        return task*500;
    }
private:
     int create_job_table(std::vector<std::string>data_tokens){
        
        int job_id = 0;
        int start = -1;
        int stop = -1;
        for(auto job:data_tokens){
            parse_time(job, start, stop);
            job_info* info = new job_info();
            info->id = ++job_id;
            info->start_time = start;
            info->end_time = stop;
            job_table[info->id]= info;
        }
        return 1;

    }

    int parse_time(std::string job_data, int& start, int& stop){
    
        auto index = job_data.find("#");
        //start  = static_cast<int>(job_data.substr(0, index).c_str());
        start = get_time(job_data.substr(0, index));
        stop = get_time(job_data.substr(index +1));

        return 1;
    }

    int get_time(std::string time){
        /*Parse the time in AM PM format and return the time in 24 hrs*/
        auto time_type_index = time.length() - 2;
        auto time_len = time_type_index;
        auto type = time.substr(time_type_index);
        auto time_val = stoi(time);
        if(type.compare("PM") == 0){
            time_val += 12; 
        }

        return time_val;
    }

    //Data members
    JobRefTree obj;
    std::map<int, job_info*> job_table;

};
int jobMachine(char* input1[])
{
    //Write code here
    return 1;
}


void main(){
    JobSchduler obj;
    //std::string input_string = "{6AM#8AM,8AM#9AM,4PM#7PM,9AM#3PM}";
    std::string input_string = "{6AM#8AM,11AM#1PM,7AM#3PM,7AM#10AM,10AM#12PM,2PM#4PM,1PM#4PM,8AM#9AM}";
    obj.ParseInput(input_string);
    obj.create_job_scheduler();
    std::cout<<obj.calculate_maximum_profit();
    /*std::vector<std::string> tokens;
    tokenize(input_string, ",");*/

}