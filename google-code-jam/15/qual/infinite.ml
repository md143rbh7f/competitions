open List
open Printf
open Scanf

let read_int () = Scanf.bscanf Scanf.Scanning.stdib " %d " (fun x -> x)

let rec read_ints n =
	if n == 0 then [] else (read_int ()) :: read_ints (n - 1)

let (--) i j =
	let rec aux n acc =
		if n < i then acc else aux (n - 1) (n :: acc)
	in aux j []

let max_n = 1005

let work () =
	let d = read_int () in
	let xs = read_ints d in
	let compute_cost n = n + List.fold_left (+) 0 (List.map (fun x -> (x - 1) / n) xs) in
	List.fold_left min max_n (List.map compute_cost (1--max_n))

let () =
	let num_cases = read_int () in
	for case_num = 1 to num_cases do
		Printf.printf "Case #%d: %d\n" case_num (work ())
	done
