#!/bin/bash
dir=$(pwd)
valgrind -q --track-fds=yes --leak-check=full --show-leak-kinds=all --show-reachable=yes ./cub3D $1
