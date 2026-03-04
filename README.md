# Ranked Choice Voting System (C++)

This project implements a **Ranked Pairs voting algorithm** to determine the winner of an election based on voter preferences.

The system records ranked votes, builds a pairwise preference matrix, sorts candidate pairs by strength of victory, and constructs a directed graph while preventing cycles.

---

## Features

- Dynamic number of candidates and voters
- Pairwise preference matrix
- Ranked pairs algorithm
- Cycle detection using DFS
- Graph-based winner determination

---

## Example Input

3
3
Alice
Bob
Charlie
Alice Bob Charlie
Bob Charlie Alice
Charlie Alice Bob

---

## Time Complexity

Let:

C = number of candidates  
V = number of voters  

Recording votes → O(V * C²)  
Creating pairs → O(C²)  
Sorting pairs → O(C² log C)  
Locking pairs → O(C³)  
Finding winner → O(C²)

Overall complexity → **O(V * C² + C³)**

---

## Technologies Used

- C++
- STL (vector, unordered_map)
- Graph algorithms
- Depth First Search (DFS)

---

## How to Run

Compile the program:
g++ ranked_voting_system.cpp -o voting

Run the program:
./voting

You can also test using the provided sample input:
./voting < sample_input.txt

---

## Project Structure

ranked-voting-system
│
├── ranked_voting_system.cpp   # Main program
├── sample_input.txt           # Example test input
└── README.md                  # Project documentation

---

## Algorithm Used

This project implements the Ranked Pairs (Tideman) voting algorithm.

Steps:
1. Record voter preferences.
2. Build a pairwise preference matrix.
3. Create candidate pairs based on victories.
4. Sort pairs by strength of victory.
5. Lock pairs while preventing cycles.
6. The candidate with no incoming edges is the winner.
   
---

## Author

Jaanvi Vohra  
Computer Engineering Student
