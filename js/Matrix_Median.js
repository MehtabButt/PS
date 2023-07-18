const findMedian = function(A){
    const rows = A.length, cols = A[0].length;
    let min = Infinity, max = -Infinity;
    let mid;
    const expectedLessThanCount = Math.floor((rows*cols)/2);

    //get min and max values
    A.forEach(a => {
        if(a[0] < min) min = a[0];
        if(a[cols-1] > max) max = a[cols-1];
    });
    //getting count of numbers less than num
    function getMatrixLessThanCount(num) {
        function getRowLessThanCount(row) {
            let l = 0, r = row.length-1;
            let mid;
            while(l <= r) {
                mid = Math.floor((l+r)/2);
                if(row[mid] <= num) l = mid+1;
                else r = mid-1;
            }
            return l;
        }
        let count = 0;
        A.forEach(a => count += getRowLessThanCount(a, num));
        return count;
    }

    //binary search
    while(min <= max) {
        mid = Math.floor((min+max)/2);
        if(getMatrixLessThanCount(mid) <= expectedLessThanCount) min = mid+1;
        else max = mid-1;
    }

    return min;
}

module.exports = {
    findMedian: findMedian
};

A = [[1, 3, 5],[2, 6, 9],[3, 6, 9]]
const med = findMedian(A)
console.log('median', med);


