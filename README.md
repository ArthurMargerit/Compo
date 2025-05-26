<div dir="" align="center">
<img src="https://gitlab.marger.it:10443/ruhtra/compo/-/wikis/CompoMe.png" >
</div>

![]( https://gitlab.marger.it:10443/ruhtra/compo/badges/master/pipeline.svg)
![]( https://gitlab.marger.it:10443/ruhtra/compo/badges/master/coverage.svg)

Welcome to CompoMe FrameWork
=====================================
# What's CompoMe ?
CompoMe is a Component FrameWork, witch facilitate the re-usability of Code and provide tool to generate code.

<div dir="" align="center">
<img src="https://gitlab.marger.it:10443/ruhtra/compo/-/wikis/compo_view.png">
</div>

For each elements in the CompoMe Model(.yaml) you can assign files generation.
We currently support many output and functionalities.

# How to use it
- [Documentations](https://gitlab.marger.it:10443/ruhtra/compo/-/wikis/home)
- [Examples](https://gitlab.marger.it:10443/ruhtra/compo/-/tree/master/Examples)
- [I want to _Contribute_]()

# Frequently Asked Questions (FAQ)
## General Questions

### What licenses are used in this project?
The project uses three main licenses: GPL for the generator, LGPL for the core libraries, and a customizable license for the generated code.

### Why are different licenses used for different parts of the project?
Different licenses are used to balance the need for open collaboration and the flexibility for users to integrate the code into various types of projects, including proprietary ones.

## Generator

###  What does the GPL license mean for the generator?
The GPL license ensures that any modifications or extensions to the generator must also be open-sourced under the GPL. This promotes a collaborative environment where improvements are shared with the community.

### Can I use the generator in a proprietary project?
If your project incorporates the generator's code directly into the product, it is subject to GPL "contamination," meaning the entire project must be open-sourced under the GPL. However, if you use the generator as a tool to create code without integrating its code into your project, the generated code is not impacted and can be licensed separately. Examples of such tools include GDB (GNU Debugger) and GCC (GNU Compiler Collection), which are used to develop and debug software without requiring the resulting software to be under the GPL.

## Core Libraries

### What does the LGPL license mean for the core libraries?
The LGPL license allows you to use the core libraries in proprietary projects without requiring you to open-source your entire project. However, any modifications to the libraries themselves must be open-sourced under the LGPL.

### Can I modify the core libraries for my project?
Yes, you can modify the core libraries, but you must distribute those modifications under the LGPL license.

## Generated Code

### Can I choose any license for the generated code?
Yes, the generated code can be licensed under any license of your choice, allowing you to select the most appropriate license for your specific use case.

### What are some common licenses I can use for the generated code?
Common licenses include MIT, Apache 2.0, and proprietary licenses. The choice depends on your project's requirements and how you wish to share or restrict the use of the code.


## Compliance and Legal

### How do I ensure I am complying with the licenses?
Make sure to read and understand the terms of each license. For GPL and LGPL, ensure that any modifications or distributions comply with their respective terms. For the generated code, choose a license that fits your needs and ensure proper attribution if required.

### What should I do if I have more questions about the licenses?

If you have more questions or need further clarification, you can contact us at ruhtra.mar@gmail.com.
### Can enterprises request a different license for their use case?

Yes, enterprises can request a different license tailored to their specific needs. Please contact us at ruhtra.mar@gmail.com to discuss licensing options that better suit your enterprise requirements.
