#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> lets;
        vector<string> digs;
        for(auto& log: logs){
            if(isdigit(static_cast<unsigned char>(log.at(log.find_first_of(" ") + 1)))){
                digs.push_back(log);
            }
            else{
                lets.push_back(log);
            }
        }
        std::sort(lets.begin(), lets.end(), [](string& x, string& y){
            string a = x.substr(x.find_first_of(" ") + 1);
            string b = y.substr(y.find_first_of(" ") + 1);
            if(a.size() >= b.size()){
                for(size_t i = 0; i < b.size();i++){
                    if(a.at(i) < b.at(i)) return true;
                    else if(a.at(i)>b.at(i)) return false;
                }
            }
            else{
                for(size_t i = 0; i < a.size();i++){
                    if(a.at(i) < b.at(i)) return true;
                    else if(a.at(i)>b.at(i)) return false;
                }
            }

            if(a.size()<b.size()) return true;
            if(a.size()>b.size()) return false;

            a = x.substr(0,x.find_first_of(" "));
            b = y.substr(0,y.find_first_of(" "));
            if(a.size() >= b.size()){
                for(size_t i = 0; i < b.size();i++){
                    if(a.at(i) < b.at(i)) return true;
                    else if(a.at(i)>b.at(i)) return false;
                }
            }
            else{
                for(size_t i = 0; i < a.size();i++){
                    if(a.at(i) < b.at(i)) return true;
                    else if(a.at(i)>b.at(i)) return false;
                }
            }
            return false;


            
        });
        for(auto& i : digs){
            lets.push_back(i);
        }
        return lets;
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
