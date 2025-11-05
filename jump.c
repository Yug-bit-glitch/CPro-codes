bool canJump(int* nums, int numsSize) {
    int max=0;
    int current =0;
    if(numsSize<=1){
        return true;
        }
    for(int i=0;i<numsSize;i++){
        if(i>max){
            return false;
        }
        if((nums[i]+i)>max){
            max=nums[i]+i;
        }
        if(i==current){
            current=max;
            if(current>=(numsSize-1)){
                return true;
        }
    }
}
return false;
}
