class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int length = mountainArr.length();
        int index, l = 0, r = length-1, peak;
        if(mountainArr.get(0)==target)
            return 0;
        map<int, int> arr;
        while(l<r)
        {
            index = (l+r)/2;
            if(arr.find(index)==arr.end())
                arr[index] = mountainArr.get(index);
            if(arr.find(index+1) == arr.end())
                arr[index+1] = mountainArr.get(index+1);

            if(arr[index]<arr[index+1])
                l = peak = index+1;
            else
                r = index;
        }
        l = 0;
        r = peak;
        while(l<=r)
        {
            index = (l+r)/2;
            if(arr.find(index)==arr.end())
                arr[index] = mountainArr.get(index);
            if(arr[index]<target)
                l = index+1;
            else if(arr[index] > target)
                r = index-1;
            else
                return index;
        }

        l = peak;
        r = length-1;
        while(l<=r)
        {
            index = (l+r)/2;
            if(arr.find(index)==arr.end())
                arr[index] = mountainArr.get(index);
            if(arr[index]>target)
                l = index+1;
            else if(arr[index] < target)
                r = index-1;
            else
                return index;
        }
        return -1;
    }
};
