#include "stockIO.h"

//opens the file
void open_file(ifstream& in, string input_name)
{
    in.open(input_name, ios::in);
}

int get_num_lines(ifstream& in)
{
    in.unsetf(ios_base::skipws);

    // count the newlines with an algorithm specialized for counting:
    int line_count = count(
        istream_iterator<char>(in),
        istream_iterator<char>(),
        '\n');

    return line_count;
}




//inputing data in doubly linked lists
void input_data(stock_info& stock, ifstream& in)
{
    string line;
    string val;
    int row_count = 0;

    //grab the first line, then grab individual parts of the line and store it in struct
    while (getline(in, line))
    {
        //cout << "grabbed " << line << endl;

        getline(in, val, '/');
        //cout << "grabbed " << val << endl;

        stock.month[row_count] = strtof(val.c_str(), NULL);
        //cout << "stock.month[row_count] = " << stock.month[row_count] << endl;

        getline(in, val, '/');
        stock.day[row_count] = strtof(val.c_str(), NULL);
        //cout << "stock.day[row_count] = " << stock.day[row_count] << endl;

        getline(in, val, ',');
        stock.year[row_count] = strtof(val.c_str(), NULL);
        //cout << "stock.year[row_count] = " << stock.year[row_count] << endl;

        getline(in, val, ':');
        stock.hour[row_count] = strtof(val.c_str(), NULL);
        //cout << "stock.hour[row_count] = " << stock.hour[row_count] << endl;

        getline(in, val, ':');
        stock.min[row_count] = strtof(val.c_str(), NULL);
        //cout << "stock.min[row_count] = " << stock.min[row_count] << endl;

        getline(in, val, ',');
        stock.sec[row_count] = strtof(val.c_str(), NULL);
        //cout << "stock.sec[row_count] = " << stock.sec[row_count] << endl;

        getline(in, val, ',');
        stock.open[row_count] = strtof(val.c_str(), NULL);
        //cout << "stock.open[row_count] = " << stock.open[row_count] << endl;

        getline(in, val, ',');
        stock.high[row_count] = strtof(val.c_str(), NULL);

        getline(in, val, ',');
        stock.low[row_count] = strtof(val.c_str(), NULL);

        getline(in, val, ',');
        stock.close[row_count] = strtof(val.c_str(), NULL);

        getline(in, val, ',');
        stock.volume[row_count] = strtof(val.c_str(), NULL);

        row_count++;
    }
}



void alloc_all_mem(stock_info& stock, int line_count)
{
    stock.year = alloc2d(line_count); // rows
    stock.month = alloc2d(line_count);
    stock.day = alloc2d(line_count);
    stock.hour = alloc2d(line_count);
    stock.min = alloc2d(line_count);
    stock.sec = alloc2d(line_count);
    stock.open = alloc2d(line_count);
    stock.high = alloc2d(line_count);
    stock.low = alloc2d(line_count);
    stock.close = alloc2d(line_count);
    stock.volume = alloc2d(line_count);
}

//TODO: Need to check that memory was allocated, make sure its not = 0
void dealloc_all_mem(stock_info& stock, int line_count)
{
    free2d(stock.year, line_count);
    free2d(stock.month, line_count);
    free2d(stock.day, line_count);
    free2d(stock.hour, line_count);
    free2d(stock.min, line_count);
    free2d(stock.sec, line_count);
    free2d(stock.open, line_count);
    free2d(stock.high, line_count);
    free2d(stock.low, line_count);
    free2d(stock.close, line_count);
    free2d(stock.volume, line_count);
}


float* alloc2d(int rows)
{
    float* ptr;
    // Dynamically allocate memory using malloc()
    ptr = (float*)malloc(rows * sizeof(float));

    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        return 0;
    }

    return ptr;
}


void free2d(float*& ptr, int rows)
{
    free(ptr);
}

