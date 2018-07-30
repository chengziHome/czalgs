//
// Created by chengzi on 18-7-17.
//

#include <vector>

class Sort{


public:

    static void printVector(std::vector<int> nums,int len){
        std::cout << "[";
        for(int i=0;i<len-1;i++){
            std::cout << nums[i] << "," ;
        }
        std::cout << nums[len-1] << "]" << std::endl;
    }

    static void insertionSort(int arr[],int num){
        for(int i=1;i<num;i++){
            int key = arr[i];
            int j = i-1;
            while(j >=0 &&  arr[j]>key){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }



    /**
     * 2.2 - 2
     * @param arr
     * @param num
     */
    static void selectionSort(int arr[],int num){
        for(int i=0;i<num-1;i++){
            int min_index = i;
            int j = i;
            for(j;j<num;j++){
                if(arr[j] < arr[min_index]){
                    min_index = j;
                }
            }
            if(min_index != i){
                int temp = arr[i];
                arr[i] = arr[min_index];
                arr[min_index] = temp;
            }
        }
    }



    /***
     * 在以前java的实现中,方便起见没有用到arr[0]这个元素,这样索引从1开始就能方便很多.
     * 即使题目中给定的是包含arr[0]的,我们也可以先排序不算arr[0]的剩下的元素.
     * 所以,下面的堆排序假设题目是:
     * 给定的nums包含nums[0]
     */

    /**
     * 堆排序的实现
     * @param nums
     * @param len
     */
    static void heapSort(std::vector<int>& nums,int len){
        for(int i=(len-1)/2;i>=1;i--){
            sink(nums,i,len-1);
        }
        int N = len-1;
        while(N>1){
            exch(nums,1,N--);
            sink(nums,1,N);
        }
        int i = 0;
        while(i<len-1 && nums[i] > nums[i+1]){
            exch(nums,i,i+1);
            i++;
        }
    }

    /**
     * 维护堆
     * @param nums
     * @param k         下沉第k个元素,(那么它的索引为k-1)
     * @param len       待排序数组长度
     */
    static void sink(std::vector<int>& nums,int k,int len){
        while(2*k <= len){
            int j = 2*k; //让j代表两个子节点中较大的序号
            if(j<len && nums[j]<nums[j+1]) j++;
            if(nums[k] >= nums[j]) break;
            exch(nums,k,j);
            k = j;
        }
    }

    static void exch(std::vector<int>& nums,int i,int j){
        if(i!=j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }

    static void testHeapSort(){
        int a[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
        int len = sizeof(a)/sizeof(a[0]);
        std::vector<int> av(a,a+len);
        heapSort(av,len);
        printVector(av,len);
    }



    /**
     * 下面实现快速排序
     */

    static void quickSort(std::vector<int>& nums,int lo,int hi){
        if(lo>=hi)
            return;
        int p = partition(nums,lo,hi);
        quickSort(nums,lo,p-1);
        quickSort(nums,p+1,hi);
    }


    static int partition(std::vector<int>& nums,int lo,int hi){
        int i = lo,j = hi+1;
        int val = nums[lo];
        while(true){
            while(nums[++i] < val) if(i==hi) break;
            while(nums[--j] > val) if(j==lo) break;
            if(i>=j) break;
            exch(nums,i,j);
        }
        exch(nums,lo,j);
        return j;
    }


    static void testQuickSort(){
        int a[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
        int len = sizeof(a)/sizeof(a[0]);
        std::vector<int> av(a,a+len);
        quickSort(av,0,len-1);
        printVector(av,len);
    }



};

