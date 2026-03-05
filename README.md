![C++](https://img.shields.io/badge/language-C%2B%2B-blue)
![Algorithm](https://img.shields.io/badge/algorithm-Ranked%20Pairs-orange)
![Graph](https://img.shields.io/badge/data%20structure-Graph-green)
![Status](https://img.shields.io/badge/status-Completed-success)


## Ranked Choice Voting System (C++)


This project implements the Ranked Pairs voting algorithm to determine the winner of an election based on voter preferences.

The system records ranked votes, builds a pairwise preference matrix, sorts candidate pairs by strength of victory, and constructs a directed graph while preventing cycles to determine the final winner.

## Demo

## Demo

Click the thumbnail below to watch the program demonstration.

[![Watch Demo](https://img.youtube.com/vi/HxeWJnZrrHo/0.jpg)](https://youtu.be/HxeWJnZrrHo)

## Features
1. Dynamic number of candidates and voters
2. Pairwise preference matrix construction
3. Ranked Pairs (Tideman) voting algorithm implementation
4. Cycle detection using Depth First Search (DFS)
5. Graph-based winner determination
6. Modular and scalable C++ implementation

## Example Input
```
3
3
Alice
Bob
Charlie
Alice Bob Charlie
Bob Charlie Alice
Charlie Alice Bob
```

## Time Complexity
## Time Complexity

Let:

C = number of candidates  
V = number of voters  

| Operation        | Complexity   |
|------------------|--------------|
| Recording votes  | O(V * C²)    |
| Creating pairs   | O(C²)        |
| Sorting pairs    | O(C² log C)  |
| Locking pairs    | O(C³)        |
| Finding winner   | O(C²)        |

Overall complexity → **O(V * C² + C³)**

# Technologies Used
>C++
>Standard Template Library (STL)
>vector
>unordered_map
>Graph Algorithms
>Depth First Search (DFS)

# How to Run
> Compile the program
     g++ ranked_voting_system.cpp -o voting
>Run the program
     ./voting
>Run using sample input
      ./voting < sample_input.txt

## Project Structure
ranked-voting-system
│
├── ranked_voting_system.cpp   # Main program
├── sample_input.txt           # Example test input
└── README.md                  # Project documentation

## Algorithm Used

This project implements the Ranked Pairs (Tideman) voting algorithm.
Steps
1. Record voter preferences
2. Build a pairwise preference matrix
3. Create candidate pairs based on victories
4. Sort pairs by strength of victory
5. Lock pairs while preventing cycles
6. The candidate with no incoming edges in the graph is declared the winner

## Possible Improvements

Future enhancements that could be added:
> GUI based voting interface
> File-based input for large elections
> Visualization of the voting graph
> Support for large-scale voting datasets

## Author

Jaanvi Vohra

## License

This project is open-source and available for educational and learning purposes.
