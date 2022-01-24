const getPermutations = function (arr, selectNumber){
    const res=[]
    if(selectNumber ===1 ) return arr.map(value => [value])

arr.forEach((fixed, index,origin) =>{
    const rest = [...origin.slice(0,index), ...origin.slice(index+1)]
    const permutations = getPermutations(rest,selectNumber -1)
    const attached = permutations.map((permutations) => [fixed, ...permutations])

    res.push([...attached])

})
    return res
}

console.log(getPermutations([1,2,3,4],3))