#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip> 

using namespace std;
//void print_data()

struct stock_info
{

    float* year;
    float* month;
    float* day;
    float* hour;
    float* min;
    float* sec;
    float* open;
    float* high;
    float* low;
    float* close;
    float* volume;
};


//************************************************************************
void open_file(ifstream& in, string input_name);

int get_num_lines(ifstream& in);

void input_data(stock_info& stock, ifstream& in);

void alloc_all_mem(stock_info& stock, int line_count);

void dealloc_all_mem(stock_info& stock, int line_count);

float* alloc2d(int rows);

void free2d(float*& ptr, int rows);

void output_data(stock_info& stock, ifstream& in);
