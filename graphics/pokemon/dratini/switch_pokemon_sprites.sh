#!/bin/bash

# Function to switch files with temporary states
switch_files() {
    local file1="$1"
    local file2="$2"
    local temp_file="${file1}2"  # Temporary file with suffix '2'

    if [[ -f "$file1" && -f "$file2" ]]; then
        # Step 1: Rename file1 to temp_file
        mv "$file1" "$temp_file"
        echo "Renamed $file1 to $temp_file"

        # Step 2: Rename file2 to file1
        mv "$file2" "$file1"
        echo "Renamed $file2 to $file1"

        # Step 3: Rename temp_file to file2
        mv "$temp_file" "$file2"
        echo "Renamed $temp_file to $file2"
    else
        echo "One or both files do not exist: $file1, $file2"
    fi
}

# Main file switches
switch_files "anim_front.png" "anim_front_gba.png"
switch_files "back.png" "back_gba.png"
switch_files "icon.png" "icon_gba.png"
switch_files "normal.pal" "normal_gba.pal"
switch_files "shiny.pal" "shiny_gba.pal"