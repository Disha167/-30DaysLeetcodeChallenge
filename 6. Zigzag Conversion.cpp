/*
logic ye hai ki pehle to htumhe dikhna chahiye ki ye kaha se kr raha pattern toh this is the pattern seedha diagonal seedha diagonal
fr dekho ki string ka kaunsa index kaha hai matrix me:
if string="PAYPALISHIRING" and numrows=4
Then ans is
0    6      12
1  5 7   11 13
2 4  8 10   
3    9      
P     I    N
A   L S  I G
Y A   H R
P     I
bs isko 1 seedhi line till numrows print krna hai, fr diagonal neeche se uppar with size numrow-2, repeat this sequence untill size_of_string

*/
class Solution {
public:
    string convert(string s, int numRows) {
       vector<vector<int>>index_of_strings(numRows);
       /*now, we enter the index of first square*/
       int outer_i=0;
       while(outer_i<s.size())
       {
        int row=0;
        int inner_i;
        for(inner_i=outer_i;inner_i<s.size()&&inner_i<outer_i+numRows;inner_i++)
        {
            index_of_strings[row].push_back(inner_i);
            // cout<<row<<" "<<inner_i<<endl;
            row++;
        }
        row=numRows-2;
        outer_i=inner_i;
        for(inner_i=outer_i;inner_i<s.size()&&inner_i<outer_i+numRows-2;inner_i++)
        {
            index_of_strings[row].push_back(inner_i);
            // cout<<row<<" "<<"diagonal "<<inner_i<<endl;
            row--;
        }
        outer_i=inner_i;
       }
       string ans="";
       for(int i=0;i<numRows;i++)
       {
        for(int j=0;j<index_of_strings[i].size();j++)
        {
            ans+=s[index_of_strings[i][j]];
        }
       }
       return ans;

    }
};
