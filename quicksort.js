function quicksort(arr) {
    if(arr.length<=1){return arr}
    let mid = arr[0]
    let i = 0, j = arr.length-1

    while (i < j) {
        while (i < j && arr[j] >= mid) {
            j--
        }
        arr[i] = arr[j]

        while (i < j && arr[i] <= mid) {
            i++
        }
        arr[j] = arr[i]
        arr[i] = mid
    }

    return quicksort(arr.slice(0,i)).concat([mid],quicksort(arr.slice(i+1,arr.length)))
}
let a = [8, 4, 2, 5, 6, 1, 9]

console.log(quicksort(a));