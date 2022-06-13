class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if(matrix.size()==0 || matrix[0].size()==0)
        {
            return false;
        }
        int low;
        int high;

        // first search in first column, use binary search
        for(low = 0, high = matrix.size() - 1; low <= high;)
        {
            size_t middle = (low + high) / 2;
            if(matrix[middle][0] < target)
            {
                low = middle + 1;
            }
            else if(matrix[middle][0] > target)
            {
                high = middle - 1;
            }
            else //we already found the element
            {
                return true;
            }
        }
        // now we have searched in the first column and know which probable row will have the solution 
         // when above loop ends, search in row[high]
        int row = high;
        if (row >= 0)
        {
            for(low = 0, high = matrix[row].size() - 1; low <= high;)
            {
                int middle = (low + high) / 2;
                if(matrix[row][middle] < target)
                {
                    low = middle + 1;
                }
                else if(matrix[row][middle] > target)
                {
                    high = middle - 1;
                }
                else // we found the element in matrix[row][middle];
                {
                    return true;
                }
            }
        }
        return false;
    }
};