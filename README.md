<p align="center">
  <img src="assets/42bangkok.jpg" alt="logo" width="auto" height="300px" />
</p>

# Push_swap

This project about sorting algorithm by using 2 stacks data structure and set of instruction that giving (ex. push, swap). Purpose of this project is finding the most efficiency way to get less possible **'instruction'**





| Language     | Limitation            | Doc | Develop on |
| :-------- | :------- | :------------------------- | :--- |
| C | 42 school rule | [subject](assets/en.subject.pdf) | Mac |

### Installation

- clone this repository
```bash
  git clone https://github.com/pvudthic/Push_swap42.git && cd Push_swap42
```
- run makefile
```bash
  make
```
### Usage/Examples

- use program by ./push_swap [int number ...]
```bash
  ./push_swap 1 -3 4 7
```
- program show list of instruction that has been used for sorting number
```bash
ra
pb
ra
ra
pa
```


- parameter details (*notes* `p` is `./push_swap`)

| Parameter | example     | Output                |
| :-------- | :------- | :------------------------- |
| biger than int | ./p 1 2147483648 | Error |
| lower than int | ./p 1 -2147483649 | Error |
| character | ./p 1 2a 3| Error |
| duplicates | ./p 0 0 | Error |
| `NULL` | ./p -null | Error |
| empty | ./p | *nothing* |
| already sorted | ./p -3 1 4 | *nothing* |
| 1 integer | ./p 42 | *nothing* |
| string contain valid | ARG="-1 2 -3"; ./p $ARG | rra |
| string contain invalid | ARG="-1 b 2 -3"; ./p $ARG | Error |





### Authors

- [@pvudthic](https://github.com/pvudthic)
- [@42intra](https://profile.intra.42.fr/users/pvudthic)


## Screenshots

![App Screenshot](https://via.placeholder.com/468x300?text=App+Screenshot+Here)

