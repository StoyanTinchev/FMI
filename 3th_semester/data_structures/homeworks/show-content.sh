#!/bin/bash

# Функция за обработка на всеки файл в дадена директория
show_content() {
    local directory=$1
    local output_file=$2
    local exclude_dirs=$3

    # Намира всички файлове, изключвайки зададените директории
    find "$directory" -type f | grep -vE "$exclude_dirs" | while read -r file; do
        {
          echo ""
          echo "$file:"
          echo "-------------------------"
          cat "$file"
          echo ""
          echo "-------------------------"
          echo ""
        } >> "$output_file"
    done
}

# Проверява дали са подадени достатъчно аргументи
if [ "$#" -lt 2 ]; then
    echo "Usage: $0 <directory> <output_file> [exclude_dirs]"
    exit 1
fi

directory=$1
output_file=$2
exclude_dirs=${3:-""} # Ако не е подаден трети аргумент, използва празен низ

# Създава или изчиства съществуващия изходен файл
> $output_file

# Извиква функцията с подадените аргументи
show_content $directory $output_file "$exclude_dirs"
