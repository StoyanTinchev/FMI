#!/bin/bash

# Функция за обработка на всеки файл в дадена директория
show_content() {
    local directory=$1
    local output_file=$2
    shift 2 # Shift past the first two arguments to get to the exclude patterns
    local exclude_patterns=("$@") # All remaining arguments are treated as exclude patterns

    # Construct a regex pattern that combines all exclude patterns
    local regex_pattern=$(printf "|%s" "${exclude_patterns[@]}")
    regex_pattern="${regex_pattern:1}" # Remove the leading '|'

    # Намира всички файлове, изключвайки зададените директории
    find "$directory" -type f | grep -vE "$regex_pattern" | while read -r file; do
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
if [ "$#" -lt 3 ]; then
    echo "Usage: $0 <directory> <output_file> [exclude_dirs...]"
    exit 1
fi

directory=$1
output_file=$2
shift 2 # Remove the first two arguments so we only pass exclude patterns to the function

# Създава или изчиства съществуващия изходен файл
> $output_file

# Извиква функцията с подадените аргументи
show_content $directory $output_file "$@"
