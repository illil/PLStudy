

let Split list pivot =
    let rec Split list less great =  
        match list with             
            | [] -> (less, great)
            | head::tail -> 
                if head > pivot then 
                    Split tail less (head::great)
                else 
                    Split tail (head::less) great
    Split list [] [] 

let rec Quicksort list =
    match list with        
        | [] | [_] -> list
        | pivot::tail -> 
            let less, great = List.partition (fun x-> x >pivot) tail
            (Quicksort less) @ pivot :: (Quicksort great)  


let Add a b = 
    a + b

let _= 
    [1;2;3;4;5;6;7] |> List.map (fun x-> x+1) |> List.sum |> printf "%d"
    ()
    
                

