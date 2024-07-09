class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double total_waiting_time = 0;
        long long chef_available_time = 0;
        
        for (const auto& customer : customers) {
            int arrival = customer[0];
            int prep_time = customer[1];
            
            // Chef starts preparing when they're available or when the customer arrives, whichever is later
            long long start_time = max(chef_available_time, (long long)arrival);
            
            // Calculate finish time
            long long finish_time = start_time + prep_time;
            
            // Calculate waiting time for this customer
            long long waiting_time = finish_time - arrival;
            
            // Add to total waiting time
            total_waiting_time += waiting_time;
            
            // Update when the chef will be available next
            chef_available_time = finish_time;  
        }
        return total_waiting_time / customers.size();

    }
};