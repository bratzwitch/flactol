# Fract-ol

A fractal visualization program that renders beautiful mathematical fractals using the MiniLibX graphics library.

## Description

Fract-ol is a project that explores the fascinating world of fractals. It renders complex mathematical sets like the Mandelbrot and Julia sets in real-time, with interactive zoom, color manipulation, and parameter changes. This project teaches computer graphics, mathematical algorithms, and optimization techniques.

## Features

- **Multiple Fractal Types**: Mandelbrot set, Julia set, and custom fractals
- **Real-time Rendering**: Smooth zooming and panning
- **Interactive Controls**: Mouse and keyboard navigation
- **Color Schemes**: Multiple color palettes and gradients
- **High Performance**: Optimized rendering algorithms
- **Parameter Adjustment**: Real-time Julia set parameter changes

## Supported Fractals

### Mandelbrot Set
The famous fractal defined by the iteration: `z = z² + c`

### Julia Set
Similar to Mandelbrot but with fixed complex parameter: `z = z² + c`

### Custom Fractals
Additional mathematical sets and variations

## Compilation

```bash
make
```

## Usage

1. Clone the repository:
```bash
git clone https://github.com/bratzwitch/fractol.git
cd fractol
```

2. Compile the program:
```bash
make
```

3. Run with fractal type:
```bash
./fractol mandelbrot
./fractol julia
./fractol [custom_fractal_name]
```

## Controls

### Mouse Controls
- **Scroll Up/Down**: Zoom in/out
- **Left Click**: Center view on clicked point
- **Mouse Movement**: Real-time Julia set parameter change (Julia fractal)

### Keyboard Controls
- **Arrow Keys**: Pan view (up, down, left, right)
- **+/-**: Zoom in/out
- **Space**: Reset view to default
- **C**: Change color scheme
- **I**: Increase iterations (better quality, slower)
- **D**: Decrease iterations (lower quality, faster)
- **ESC**: Exit program

## Examples

**Basic usage:**
```bash
# Render Mandelbrot set
./fractol mandelbrot

# Render Julia set
./fractol julia

# Custom parameters (if supported)
./fractol julia -0.7 0.27015
```

## Mathematical Background

### Mandelbrot Set
For each point c in the complex plane:
- Start with z₀ = 0
- Iterate: zₙ₊₁ = zₙ² + c
- If |z| remains bounded after many iterations, c is in the set

### Julia Set
For a fixed complex parameter c:
- For each point z₀ in the complex plane
- Iterate: zₙ₊₁ = zₙ² + c
- If |z| remains bounded, z₀ is in the set

## Implementation Details

### Core Algorithm
```c
int	mandelbrot(double real, double imag, int max_iter)
{
	double	z_real = 0;
	double	z_imag = 0;
	double	temp;
	int		iter = 0;

	while (z_real * z_real + z_imag * z_imag <= 4 && iter < max_iter)
	{
		temp = z_real * z_real - z_imag * z_imag + real;
		z_imag = 2 * z_real * z_imag + imag;
		z_real = temp;
		iter++;
	}
	return (iter);
}
```

### Optimization Techniques
- **Escape Radius**: Early termination when |z| > 2
- **Iteration Limits**: Configurable maximum iterations
- **Pixel-level Calculations**: Direct coordinate mapping
- **Color Interpolation**: Smooth color transitions

## File Structure

- `fractol.c`: Main program and initialization
- `mandelbrot.c`: Mandelbrot set implementation
- `julia.c`: Julia set implementation
- `controls.c`: Mouse and keyboard event handling
- `utils.c`: Helper functions
- `colors.c`: Color scheme management
- `fractol.h`: Header file with prototypes
- `Makefile`: Compilation rules

## Color Schemes

The program supports multiple color palettes:
- **Classic**: Traditional blue-white gradient
- **Fire**: Red-orange-yellow gradient
- **Rainbow**: Full spectrum colors
- **Psychedelic**: Vibrant, contrasting colors
- **Monochrome**: Grayscale variations

## Performance Tips

- Lower iteration counts for real-time interaction
- Higher iteration counts for detailed final renders
- Zoom gradually for smooth experience
- Use appropriate window size for your system

## Requirements

- **MiniLibX**: Graphics library (provided by 42)
- **GCC**: Compiler
- **Make**: Build system
- **X11**: For Linux systems
- **Math Library**: Link with `-lm`

## Installation Dependencies

**MacOS:**
```bash
# MiniLibX is usually provided by 42
```

**Linux:**
```bash
sudo apt-get install xorg libxext-dev zlib1g-dev
```

## Error Handling

- Invalid arguments validation
- Memory allocation checking
- Window creation verification
- Mathematical overflow protection

## Testing

```bash
# Test different fractals
./fractol mandelbrot
./fractol julia

# Test zoom and navigation
# Use mouse wheel and arrow keys

# Test color changes
# Press 'C' while program is running
```

## Mathematical Extensions

Possible enhancements:
- **Burning Ship**: Alternative fractal formula
- **Newton's Method**: Root-finding fractals
- **Phoenix**: Additional Julia-type fractal
- **3D Fractals**: Mandelbulb visualization

## Author

Viacheslav Moroz - 42 Student
