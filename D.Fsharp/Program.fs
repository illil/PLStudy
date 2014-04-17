


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
        | head::tail -> 
            let pivot = head
            let less, great = Split tail pivot
            (Quicksort less) @ pivot :: (Quicksort great)  
        

let _= 
    let data = Quicksort [7;2;3;1;6;5]
    data |> List.map (fun x -> printf "%d " x)
    ()
                

