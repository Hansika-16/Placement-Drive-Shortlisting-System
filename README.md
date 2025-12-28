# Placement Drive Shortlisting System

A command-line C application that evaluates candidates based on academic and skill-based parameters and generates a ranked shortlist using a priority queue (Max Heap).

## Overview

This project manages candidate details such as CGPA, coding skills, technical knowledge, projects, communication skills, internships, and backlogs. Candidates are first filtered based on minimum CGPA and backlog status, and then ranked using a weighted final score. A Max Heap is used to generate the final shortlist in descending order of merit.

## Core Concepts Used

- Structures (`struct`) to store candidate information  
- Arrays to manage multiple candidates  
- Weighted score calculation using basic mathematics  
- Filtering logic based on CGPA and backlog status  
- Max Heap (Priority Queue) for candidate ranking  
- Heap operations (insert and extract)  
- Menu-driven programming  

## Workflow

1. Program starts and displays the main menu  
2. User adds candidate details  
3. System calculates the final score automatically  
4. User views all registered candidates  
5. Candidates are filtered based on minimum CGPA and no backlogs  
6. Filtered candidates are inserted into a Max Heap  
7. Candidates are ranked by extracting from the heap  
8. Final shortlist is displayed  
9. Program exits safely  


## Features

- Add candidate details  
- Display all registered candidates  
- Filter candidates based on CGPA and backlog criteria  
- Calculate a weighted final score  
- Generate a ranked final shortlist  
- Menu-driven terminal interface  

## Tech Stack

Language:
- C  

Concepts:
- Structures (struct)
- Arrays
- Heap (Max Heap / Priority Queue)
- Filtering and Ranking Logic
- Menu-driven Programming  

Libraries:
- stdio.h
- string.h
