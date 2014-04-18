module Main


let Add a b = 
    a + b

let AddUncurry (a,b) = 
    a + b

let _= 
    let i = Add 1 
    let j = i 2
    ()
    
                

