//
// Created by chengzi on 18-7-20.
//
#include <vector>



class Divide{

    /**
     * 分治的的直观理解是:将大问题化成小问题.但是更加重要的是,问题小到一定程度,就不是问题了
     * 其实分治算法的过程在于回溯:的merge算法.
     */
public:


    /**
     * 归并排序,没加阈值
     * @param nums
     * @param aux
     * @param lo
     * @param hi
     */
    static void mergeSort(std::vector<int>& nums,std::vector<int>& aux,int lo,int hi){
        if(lo==hi)
            return;
        int mid = (lo + hi)/2;
        mergeSort(nums,aux,lo,mid);
        mergeSort(nums,aux,mid+1,hi);
        merge(nums,aux,lo,mid,hi);
    }

    static void merge(std::vector<int>& nums,std::vector<int>& aux,int lo,int mid,int hi){
        int p = lo,q = mid+1;
        for(int i=lo;i<=hi;i++){
            aux[i] = nums[i];
        }
        for(int k=lo;k<=hi;k++){
            if(p>mid) nums[k] = aux[q++];
            else if(q>hi) nums[k] = aux[p++];
            else if(aux[p] < aux[q]) nums[k] = aux[p++];
            else nums[k] = aux[q++];
        }
    }


    /**
     *
     *
     *
     * @param nums
     * @param lo
     * @param hi
     * @return
     *      返回的vector的长度为3,分别是左索引,右索引,最大值
     */
    static std::vector<int> find_max_subarray(std::vector<int>& nums,int lo,int hi){
        std::vector<int> res(3);
        if(lo>=hi){
            res[0] = lo;
            res[1] = hi;
            res[2] = nums[lo];
            return res;
        }
        int mid = (lo + hi)/2;
        std::vector<int> left = find_max_subarray(nums,lo,mid);
        std::vector<int> right = find_max_subarray(nums,mid+1,hi);
        std::vector<int> middle = find_cross_arrays(nums,lo,mid,hi);

        if(left[2]>=right[2] && left[2]>=middle[2]){
            return left;
        }else if(right[2]>=left[2] && right[2]>=middle[2]){
            return right;
        }else{
            return middle;
        }

    }

    static std::vector<int> find_cross_arrays(std::vector<int>& nums,int lo,int mid,int hi){
        int left_sum = 0;
        int left_max = INT32_MIN;
        int left_max_index;
        for(int i=mid;i>=lo;i--){
            left_sum += nums[i];
            if(left_sum>left_max){
                left_max = left_sum;
                left_max_index = i;
            }
        }
        int right_sum = 0;
        int right_max = INT32_MIN;
        int right_max_index;
        for(int i=mid+1;i<=hi;i++){
            right_sum += nums[i];
            if(right_sum>right_max){
                right_max = right_sum;
                right_max_index = i;
            }
        }

        std::vector<int> res(3);
        res[0] = left_max_index;
        res[1] = right_max_index;
        res[2] = left_max + right_max;
        return res;

    }


    static void testFindMaxSubarray(){
        int a[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
        int len = sizeof(a)/sizeof(a[0]);
        std::vector<int> av(a,a+len);
        std::vector<int> res = find_max_subarray(av,0,len-1);
        std::cout << res[0] << "," << res[1] << "," << res[2] << std::endl;


    }



};




