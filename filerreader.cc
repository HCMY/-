#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <numeric>
#include <iostream>
#include <functional>


std::vector<std::vector<double>> file_reader(const std::string file_path, const char delimiter=','){
    std::ifstream f;

    f.open(file_path);
    if(!f.is_open()){
        std::cerr << "Exception opening file";
        exit(0);
    }

    std::string line, val;
    std::vector<std::vector<double>> array;

    while (std::getline (f, line)) {
        std::vector<double> v;
        std::stringstream s (line);
        while (getline (s, val, delimiter))
            v.push_back (std::stod(val));
        array.push_back (v);
    }
    f.close();

    return array;

}


std::vector<std::vector<double>> product(const std::vector<std::vector<double>> &matrix){
    std::vector<std::vector<double>> res;
    std::vector<double> tmp;

    for(auto row_out:matrix){
        for(auto row_inner:matrix){

        double product = std::inner_product(row_out.begin(),
                                               row_out.end(),
                                               row_inner.begin(),
                                               0.0f);
  
        tmp.push_back(product);

        }

        res.push_back(tmp);
        tmp.clear();
    }

    return res;
}

int main (int argc, char **argv) {

    std::string f_path = "test.txt";
    std::vector<std::vector<double>> res = file_reader(f_path,' ');
    for(auto row:res){
        for (auto& val : row)
            std::cout << val << "  ";
        std::cout << "\n";
    }

    std::cout<<"======================="<<std::endl;
    std::vector<std::vector<double>> product_res = product(res);
    for(auto row:product_res){
        for (auto& val : row)
            std::cout << val << "  ";
        std::cout << "\n";
    }


}
