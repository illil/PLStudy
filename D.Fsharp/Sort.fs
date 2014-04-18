module Sort




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