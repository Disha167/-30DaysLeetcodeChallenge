//🎯DAY 53 PROBLEM 1
//It is a normal dfs problem, just one condition is important to consider that may be forgotten. Normally, dfs can be used to call for all the 4 directions, if out of bound 
//condition is there, then it is returned. If it is not org_color, then it dosen't have to be changed. If it is already new_color, then also it dosen't have to be 
//changed(take care).
class Solution {
public:
    void dfs(vector<vector<int>>&image, int sr, int sc, int org_color, int new_color)
    {
        if(sr<0||sr>=image.size()||sc<0||sc>=image[0].size()||image[sr][sc]!=org_color)
           return;
        //very important condition to be dealt when org_color and new_color are same
        //i.e. in case of image:
        //0 0 0
        //0 1 1
        //sr=1, sc=1, new_color=1 and org_color is also 1
        //so when 1 1, will call for 2,1 ideally it should return as it is already 1
        //but when it will get in above condition it is equal to org_color so it will
        //go inside call for 2,1 then 2,1 will call for 1,1 then infinte loop will color
        //So, to prevent it we also check that if cell is new color already no need to make
        //it return . This can also be dealt using visited array.
        if(image[sr][sc]==new_color)
            return;
          cout<<sr<<" "<<sc<<endl;
        image[sr][sc]=new_color;
        dfs(image,sr+1,sc,org_color,new_color);
        dfs(image,sr-1,sc,org_color,new_color);
        dfs(image,sr,sc-1,org_color,new_color);
        dfs(image,sr,sc+1,org_color,new_color);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
         int new_color=newColor;
         vector<vector<int>>new_img=image;
         int org_color=image[sr][sc];
        dfs(new_img,sr,sc,org_color,new_color);
        return new_img;
    }
};
