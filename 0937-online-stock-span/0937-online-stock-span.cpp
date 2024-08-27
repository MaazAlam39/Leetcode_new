// class StockSpanner {
// public:
//     stack<pair<int,int>>s;
//     StockSpanner() {
        
//     }
    
//     int next(int price) {
//       vector<int>v;
//       for(int i=0;i<s.size();i++){
//         if(s.size()==0)v.push_back(-1);
//         else if(s.size()>0 && s.top().first>price[i]) v.push_back(s.top().second);
//         else if(s.size()>0 && s.top().first <= price[i]){
//             while(s.size()>0 && s.top().first <=price[i]){
//                 s.pop();
//             }
//             if(s.size()==0)v.push_back(-1);
//             else v.push_back(s.top().second);
//         }
//         s.push({price[i],i});
//       }  
//       for(int i=0;i<v.size();i++){
//         v[i]=i-v[i];
//       }
//       return v;
//     }
// };

// /**
//  * Your StockSpanner object will be instantiated and called as such:
//  * StockSpanner* obj = new StockSpanner();
//  * int param_1 = obj->next(price);
//  */


class StockSpanner {
public:
    stack<pair<int,int>> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        long long int count=1;
        while(s.size()!=0 && s.top().first<=price){
            count=count+s.top().second;
            s.pop();
        }
        s.push({price,count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */