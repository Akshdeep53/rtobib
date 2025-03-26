#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<typeinfo>
#include<dirent.h>
#include<stdio.h>

void app_cite(std::vector<std::string> in_file, std::string out_file);
void ris_files();
extern std::vector<std::string> names;
/*
TI = title
T1 = title
AU = author
A1 = author
A2 = author
A3 = author
A4 = author
ED = author
ET = edition
AD = address
T2 = journal
JA = journal
JF = journal
JO = journal
PB = publisher
Y1 = year/month/date
PY = year
DA = year/month/date
VL = volume
VO = volume
IS = number
M3 = doi: 
DI = doi
DO = doi
DOI = doi
L3 = DOI
L1 = url
L2 = url
UR = url
N1 = note
NO = note
RN = note
{SP-EP} = pages


@article{file_name,
author={},
title={},
journal={},
year={},
month={},
day={},
publisher={},
volume={},
number={},
pages={},
doi={},
url={}
address={}
note={}
}
*/
