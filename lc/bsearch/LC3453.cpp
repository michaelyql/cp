using ll = long long;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        int ymax = -2e9;
        int ymin = 2e9;
        int n = squares.size();
        vector<pair<int, ll>> ycoords; // y coord and area 
        double total_area = 0;
        
        for (int i = 0; i < n; i++) {
            int y = squares[i][1];
            int width = squares[i][2];
            double area = 1.0 * width * width;
            
            ymax = max(ymax, y + width);
            ymin = min(ymin, y);
            ycoords.push_back({ y, width }); 
            total_area += area;
        }
        // cout <<"total area="<<total_area<<endl;
        
        sort(ycoords.begin(), ycoords.end(), [](const pair<int, ll>& p1, const pair<int, ll>& p2) {
            if (p1.first != p2.first) return p1.first < p2.first;
            else return p1.second < p2.second;
        });
        
        double low = ymin;
        double high = ymax;
        double delta = 0.000005; 
        
        // cout << "ymin="<<ymin<<", ymax="<<ymax<<endl;
        
        while (high - low > delta) {
            double mid = low + (high - low) / 2;
            double area = 0;
            int k = 0;
            // cout << "mid="<<mid<<endl;
            for (k = 0; k < ycoords.size(); k++) {
                // cout<<"ycoords[k].first"<<ycoords[k].first<<endl;
                // cout<<"1.0 * ycoords[k].first + ycoords[k].second"<<1.0 * ycoords[k].first + ycoords[k].second<<endl;
                if (1.0 * ycoords[k].first + ycoords[k].second > mid) break;
                // cout <<"cur height="<<1.0 * ycoords[k].first + ycoords[k].second<<endl;
                area += 1.0 * ycoords[k].second * ycoords[k].second;
            }
            int yy = ycoords[k].first;
            
            if (yy <= mid) {
                for (int i = k; i < ycoords.size(); i++) {
                    if (ycoords[i].first > mid) break;
                    if (ycoords[i].first + ycoords[i].second >= mid) {
                        area += (mid - ycoords[i].first) * ycoords[i].second;   
                    } else {
                        area += 1.0 * ycoords[i].second * ycoords[i].second;
                    }
                }
            }
            // cout <<"area="<<area<<endl;

            // if area below is less than area above
            if (area < 1.0 * total_area - area) {
                low = mid + delta;
            } else {
                high = mid - delta;
            }
        }
        
        
        return low;
    }
};
