# svg-deoptimise

`svg-deoptimise` is a simple C program designed to improve the readability of SVG files. Optimized SVG files often have all their content in a single line, making it challenging for humans to read and understand.

This program takes a destination folder and source SVG files as arguments, then outputs a deoptimized version of each file with proper line breaks for improved readability.

## Usage

```bash
./svg-deoptimise <destination_folder> <source_svg_file_1> <source_svg_file_2> ...
```

- `<destination_folder>`: The folder where deoptimized SVG files will be saved.
- `<source_svg_file_1> <source_svg_file_2> ...`: List of source SVG files to be deoptimized.

### Example

```bash
./svg-deoptimise output_folder input_file1.svg input_file2.svg
```

This command will deoptimize `input_file1.svg` and `input_file2.svg`, saving the deoptimized versions in the `output_folder`.

## Building the Program

To build the program, use a C compiler. For example, with `gcc`:

```bash
gcc -o svg-deoptimise main.c
```