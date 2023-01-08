# ATPG FAN
## v2023   &emsp; LaDSII
## CONTENTS

> **I.    Introduction**<br />
> **II.   Directory Structure**<br />
> **III.  Usage**<br />
> **IV.   Revision History**<br />
> **V.    Authors**<br />


## I. INTRODUCTION

**This package is an Automatic Test Pattern Generation(ATPG) and fault simulation tool based on the FAN algorithm[1].** <br />
**This package includes the implementation of  Fault Collapsing, Staitc Test Compression, Dynamic Test Compression and Multiple Fault Orderings.** <br />

## II. FILES STRUCTURE

> **```./ATPG_UserGuide_20230108.pdf``` : The User Manual** <br />
> **```./bin/``` : Binary Files After Compilation** <br />
> **```./include/``` : The Header Files Included in and copied from ```./pkg```** <br />
> **```./lib/``` : Binary Library Files After Compilation** <br />
> **```./mod_netlist/```, ```./netlist/``` : Testbench circuits[2]** <br />
> **```./pat/``` : Stores the generated Patterns** <br />
> **```./pkg/``` : The Source Code** <br />
>> **```./pkg/common``` : For supporting common command line instructions** <br />
>> **```./pkg/core``` : The main algorithm implemented** <br />
>> **```./pkg/fan``` : For supporting user added command line instructions** <br />
>> **```./pkg/interface``` : The interface for reading testbench circuits** <br />

> **```./rpt/``` : Stores the report after ATPG or fault simulation** <br />
> **```./script/``` : Complete Example Scripts for running ATPG and fault simulation on the testbench circuits** <br />
> **```./techlib/``` : The cell libraries[3]** <br />
> **```./copyHeader.sh``` : For the convenience of users using the intellicense of a code editor.** <br />
> **```*.mk``` : Included in other makefiles** <br />

## III REQUISITES
> Bison <br />
> Lex/Flex <br />
> C++11 <br />

## IV. USAGE

> **Compile:**<br />
> &emsp;	```make clean``` <br />
> &emsp;	```make``` <br />

> **Run ATPG:**<br />
> &emsp;	```./bin/opt/fan -f script/atpg.script``` <br />
<br />

> **Run fault simulation:**<br />
> &emsp;	```./bin/opt/fan -f script/fsim.script``` <br />


## V. REVISION HISTORY

**v2013 - Initial release.** <br />
**v2014 - Code Modifications.** <br />
**v2023 - Code refactor for open source project.** <br />


## VI. AUTHORS

**Original Authors -** Lin Hio-Ting, Hsu Po-Ya, Liao Kuan-Yu  <br />
**v2013 -** Han Cheng-You, Chen Ching-Yu, Chiang Kuan-Ying, Wang Ying-Hsu, Chen Po-Hao, Lin Kuo-Yu, Pan Chun-Han, Li Chia-An, Tsai Chia-Ling, Hsu Ling-Yun <br />
**v2014 -** He Yu-Hao, Cai Zong-Yan, How Bo-Fan, Li Yu-Qing, Huang Guan-Yan, Xiao Zhi-Long, Lin Kun-Wei, Lin Shi-Yao, Chen You-Wei, Li Guan-De <br />
**v2023 -** Wang Wei-Shen, Chang Hsin-Tzu, Pan Yu-Hung, Liang Zhe-Jia <br />

## VII. References

**[1] FAN algorithms -** Fujiwara and Shimono, "On the Acceleration of Test Generation Algorithms," in IEEE Transactions on Computers, vol. C-32, no. 12, pp. 1137-1144, Dec. 1983.  <br />
**[2] Testbench circuits -** Brglez, Franc, David Bryan, and Krzysztof Kozminski. "Combinational profiles of sequential benchmark circuits." 1989 IEEE International Symposium on Circuits and Systems (ISCAS). IEEE, 1989.<br />
**[3] Cell Library -** ```./TECHLIB_LICENSE```<br />
both ```./techlib/mod_nanagate45.mdt``` and ```./techlib/NangateOpenCellLibrary.v``` is under ```./TECHLIB_LICENSE```<br />
***Copyright (c) 2013 LaDS. All Rights Reserved.***