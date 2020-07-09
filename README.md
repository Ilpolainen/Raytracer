# Raytracer

This is a learning project with no use case value. It is based on different tutorials for understanding all the aspects of ray-tracing rendering AND c++. Props to Peter Shirley whose lectures I'm using as a starting point. At first some of the code will be written following closely his example code in https://www.realtimerendering.com/raytracing/Ray%20Tracing%20in%20a%20Weekend.pdf. 

Once my understanding of c++ goes further, I will only use the basic raytracing knowledge achieved. Strong restructuring and modification has already been made in the first commit.

![](https://github.com/Ilpolainen/Raytracer/blob/master/Project/Images/qualitySpecular4.jpg)

## Long Term Goal

- Make a ray-tracing based render engine with c++ ( for show-off and learning, applications' practical value expected to be nothing. ).

## Iteration one

- Implement somekind of raytraycer which can produce image file of some format starting from nothing but own classes and standard c++ libraries.

ACHIEVED!

( Spheres supported with one material! )

## Iteration two

- Add the other features in Peter Shirleys lecture tutorial. ( materials: metal and dielectric, positionable camera, field of view, defocus blur )

ACHIEVED

## Iteration three

- Add triangle support
- Add textures and simple UV mapping
- Add lights
- Refactor
- GPU support and parallel computing
- Separate rendering from file writing

