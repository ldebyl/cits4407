#!/bin/bash
# Generates a text file detailing software versions used in the project.
{
	printf "Report prepared: %s\n\n" "`date`"
	echo "This assignment was prepared and tested in the following environment:"
	uname -a
	sort --version
	for cmd in bash sort sed; do
		printf "\n\nCommand: %s\nPath: %s\n" ${cmd} `which ${cmd}`
		${cmd} --version
	done
	awk -W version
} > environment.txt
