#include "api_down.h"
#include "stockIO.h"

using namespace std;

int main(int argc, char* argv[])
{
    yfapi::YahooFinanceAPI api;
    ifstream in;

    //download data
    api.download_ticker_data("aapl", "2010-01-01", "2021-10-07");

    //stock data interval
    api.set_interval(DAILY);


    stock_info stock;
    int line_count = 200; 
    //cout << "there are " << line_count << "lines\n";

    //open file
    cout << "Opening file: " << "aapl_.csv" << endl;
    open_file(in, "aapl_.csv");

    //make sure files successfully opened
    if (in.is_open())
        cout << "Openned input file sucessfully\n";
    else
    {
        cout << "Unable to open input file: " << argv[1] << endl;
        return 0;
    }


    //TODO: need to reset iterator somehow
    line_count = get_num_lines(in);
    line_count++; //have to add one for some reason, otherwise allocation breaks
    cout << "Num of lines = " << line_count << endl;

    //reset to start of file
    in.clear();
    in.seekg(0);

    //allocate memory
    alloc_all_mem(stock, line_count);
    cout << "allocated memory sucessfully\n";


    //********************************************************
    //input data
    input_data(stock, in);
    cout << "Inputted data\n";

    //********************************************************
    dealloc_all_mem(stock, line_count+1);
    in.close();
    //datatable::DataTable dt2 = api.get_ticker_data("aapl", "2010-01-01", "2020-10-01", true);

    return 0;
}