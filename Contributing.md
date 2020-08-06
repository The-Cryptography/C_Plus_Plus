# CONTRIBUTION GUIDELINES

## Before contributing
Welcome to [The Cryptography/C-Plus-Plus](https://github.com/The-Cryptography/C_Plus_Plus)! Before submitting pull requests, please make sure that you have **read the whole guidelines**. If you have any doubts about this contribution guide, please open [an issue](https://github.com/The-Cryptography/C_Plus_Plus/issues/new) and clearly state your concerns.

## Contributing
### Contributor
We are very happy that you consider implementing algorithms and data structures for others! This repository is referred to and used by learners from around the globe. Being one of our contributors, you agree and confirm that:
- You did your own work.
    - No plagiarism allowed.  Any plagiarized work will not be merged.
- Your work will be distributed under [MIT License](License) once your pull request has been merged.
- You submitted work fulfils or mostly fulfils our styles and standards.

**New implementation** New implementation are welcome!

**Improving comments** and **adding tests** to existing algorithms are much appreciated.

**Issues** Please avoid opening issues asking to be "assigned” to a particular algorithm.  This merely creates unnecessary noise for maintainers.  Instead, please submit your implementation in a pull request and it will be evaluated by project maintainers.

### Making Changes

#### Code
- Please use the directory structure of the repository.
- File extension for code should be *.h *.cpp.
- Don't use **bits/stdc++.h** because this is quite Linux specific and slows down the compilation process.
- Avoid using **struct** and instead use the **class** keyword.
- You can suggest reasonable changes to existing algorithms.
- Strictly use snake_case (underscore_separated) in filenames.
- If you have added or modified code, please make sure the code compiles before submitting.
- Please conform to [doxygen](https://www.doxygen.nl/manual/docblocks.html) standard and document the code as much as possible. This not only facilitates the readers but also generates the correct info on website.
- **Be consistent in use of these guidelines.**

#### Documentation
- Make sure you put useful comments in your code.  Do not comment things that are obvious.
- Please avoid creating new directories if at all possible. Try to fit your work into the existing directory structure. If you want to create a new directory, then please check if a similar category has been recently suggested or created by other pull requests.
- If you have modified/added documentation, please ensure that your language is concise and contains no grammar errors.
- Do not update README.md along with other changes, first create an issue and then link to that issue in your pull request to suggest specific changes required to README.md
- The repository follows [Doxygen](https://www.doxygen.nl/manual/docblocks.html) standards.
Please ensure the code is documented in this structure. Sample implementation is given below.

#### Test
- Make sure to add examples and test cases in your main() function.
- If you find any algorithm or document without tests, please feel free to create a pull request or issue describing suggested changes.
- Please try to add one or more `test()` functions that will invoke the algorithm implementation on random test data with expected output. Use `assert()` function to confirm that the tests will pass.
