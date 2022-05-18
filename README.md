# lavaResawndz
A full reimplementation of Jaklub's Sawndz program, built on top of [lavaBRSARLib](https://github.com/QuickLava/lavaBRSARLib), primarily for use with SuperSawndz.

## Fixed Issues
This implementation of the program seeks to address two primary issues with the original Sawndz program:
1. Previously, produced .sawnd files would sometimes wind up stuck together, which could result in substantially larger than expected files. This could often be circumvented by exporting the .sawnd file multiple times, but failing to do so would leave users with improperly-formed .sawnd files, which leads directly to the second issue.
2. The original program's import function took for granted that provided .sawnd would be well-formed, and imported everything past the .sawnd header section into the .brsar, without checking the length of the import. As a result, attempting to import the conjoined .sawnd files mentioned previously would cause more data than expected to be overwritten, corrupting anything present in that location. I suspect this is the cause of a fair bit of the general instability associated with .brsar editing in the past.

This newer implementation fixes the first issue by configuring its file-output streams such that any generated .sawnd files overwrite existing ones, rather than appending to them.

The second issue was solved indirectly: before importing a given .sawnd file, the program will check whether any further .sawnd files are stuck to it.
If any are, instead of importing anything, the program will split them into individual .sawnd files in the program directory.
Produced files will be named as such:

> ResawndzSplit_AAAA_BB_(Group_CCC_0xDDD).sawnd

Here, AAAA is a random identifier number for the split, BB denotes the position of the file in the split, and CCC and DDD denote the file's target Group ID in decimal and hexadecimal respectively. The user may then import the split file of their choosing.

## Other Changes
This program additionally implements further error checking elsewhere in the import process.
For instance, it will check to ensure that the files contained in a given .sawnd file are actually contained in the group it represents, with allowances made to ensure out-of-region versions of the same file import correctly.
Beyond that, the program should produce more meaningful error messages than the previous iteration did, which should help inform users' investiagtions into how to fix problems they're having.

## Other Notes
If anything goes wrong while using this program, feel free to DM me either on Twitter @QuickLava or on Discord @ QuickLava#6688 for assistance!
