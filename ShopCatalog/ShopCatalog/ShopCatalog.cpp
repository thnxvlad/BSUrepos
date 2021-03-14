#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <vector>

using namespace std;

const int  INF = 2e9;

map<string, set<pair<float, string>>> ReadData(string& FilePath) {
    ifstream fin(FilePath);

    map<string, set<pair<float, string>>> Data;

    string curr_product;
    while (fin >> curr_product) {
        float curr_price;
        fin >> curr_price;
        string curr_shop;
        fin >> curr_shop;
        Data[curr_product].insert(pair<float, string>(curr_price, curr_shop));
    }
    return Data;
}

map<string, multimap<string, float>> ReadData2(string& FilePath) {
    ifstream fin(FilePath);

    map<string, multimap<string, float>> Data;
    string curr_product;
    while (fin >> curr_product) {
        float curr_price;
        fin >> curr_price;
        string curr_shop;
        fin >> curr_shop;

        Data[curr_shop].insert(pair<string, float>(curr_product, curr_price));
    }
    return Data;
}

pair<pair<float, string>, pair<float, string>>
GetExtremesPrices(string& product, map<string, set<pair<float, string>>>& catalog) {
    pair<float, string> minimum, maximum;
    minimum = *catalog[product].begin();
    maximum = *catalog[product].rbegin();
    return make_pair(minimum, maximum);
}

pair <float, string> CheckList(vector<string>& list, map<string, multimap<string, float>>& catalog) {
    pair<float, string> res((float)INF, "error");
    for (auto&& shop : catalog) {
        float sum_price = 0;
        bool cond = true;
        for (auto&& product : list) {
            auto it = shop.second.equal_range(product);
            if (it.first == shop.second.end()) {
                cond = false;
                break;
            }
            float min_price = (float)INF;
            for (auto i = it.first; i != it.second; i++)
                min_price = min(min_price, i->second);
            sum_price += min_price;
        }
        if (!cond) continue;
        if (sum_price < res.first) res = pair<float, string>(sum_price, shop.first);
    }
    return res;
}

int main() {
    string FilePath; cin >> FilePath;
    map<string, set<pair<float, string>>> catalog; //  product    price per liter / kg    shop
    map<string, multimap<string, float>> catalog2; //  shop    product    price per liter / kg
    catalog = ReadData(FilePath);
    catalog2 = ReadData2(FilePath);

    int q_type = 1;
    while (q_type != -1) {
        cout << "\nPlease, write type of question\n";
        cin >> q_type;
        if (q_type == -1) return 0;
        if (q_type == 1) {
            cout << "\nPlease write name of product.\n";
            string product;
            cin >> product;
            pair<pair<float, string>, pair<float, string>> res = GetExtremesPrices(product, catalog);
            cout << "\nMin: " << res.first.first << " " << res.first.second << "\n" <<
                "Max: " << res.second.first << " " << res.second.second << "\n";
        }
        if (q_type == 2) {
            cout << "\nPlease write list of product and finish this with 'end'.\n";
            vector<string> list;
            string curr_product;
            cin >> curr_product;
            while (curr_product != "end") {
                list.push_back(curr_product);
                cin >> curr_product;
            }
            pair<float, string> res = CheckList(list, catalog2);
            cout << "\nMin Price: " << res.first << " Shop: " << res.second << "\n";
        }
    }
    return 0;
}
