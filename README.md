<p align="center">
  <img src="assets/42bangkok.jpg" alt="logo" width="auto" height="auto" />
</p>

# Push_swap

This project about sorting algorithm by using 2 stacks data structure and set of instruction that giving (ex. push, swap). Purpose of this project is finding the most efficiency way to get less possible **'instruction'**

| Language     | Limitation            | Doc | Develop on | Score |
| :-------- | :------- | :------------------------- | :--- | :--- |
| C | 42 school rule | [subject](assets/en.subject.pdf) | Mac | [??%](https://projects.intra.42.fr/42cursus-push_swap/pvudthic) |

(***notes*** *All of this repository information is used for school evaluation and disseminate knowledge only*)

## Understanding project

- [About project](https://github.com/pvudthic/Push_swap42/wiki/About-project)
- [Algorithm](https://github.com/pvudthic/Push_swap42/wiki/Algorithm)
- [Flow chart](https://github.com/pvudthic/Push_swap42/wiki/Flow-Chart)
- [Sort Checker](https://github.com/pvudthic/Push_swap42/wiki/Sort-checker)

### Tools
| Manual Random number     | Tester            | Visualizer | Algorithm comparison |
| :------------------------------------------------------------------------------------------ | :------------------- | :--------------------------- | :---------------------------- |
| [link](https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php) | [link]() | [link](https://github.com/Niimphu/push_swap_visualiser) | [link](https://www.toptal.com/developers/sorting-algorithms) |
  
## Installation

- clone this repository
```bash
  git clone https://github.com/pvudthic/Push_swap42.git && cd Push_swap42
```
- run makefile
```bash
  make
```

## Usage/Examples

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


## References
- [Push Swap in less than 4200 operations](https://medium.com/@ulysse.gerkens/push-swap-in-less-than-4200-operations-c292f034f6c0)
- [push_swap 가이드](https://automatic-saltopus-34b.notion.site/push_swap-c15e62229b9541d78fadec4d6aae8b50)

## Authors

- [@pvudthic](https://github.com/pvudthic)
- [@42intra](https://profile.intra.42.fr/users/pvudthic)
