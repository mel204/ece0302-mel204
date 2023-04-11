#include <cstdlib>
#include <iostream>
#include "lib/image.h"
#include "list.hpp"
#include "queue.hpp"

struct Coordinates
{
  int rows = 0;
  int cols = 0;
};

int main(int argc, char *argv[])
{
  // get input/output file names from command line arguments
  if (argc != 3) {
    std::cout << "Usage: pathfinder "
              << "<first_input_filename> <second_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;
  }

  std::string input_file = argv[1];
  std::string output_file = argv[2];

  

  try
  {
    //read image from file
    Image<Pixel> image = readFromFile(input_file);
    //make copy of image
    Image<Pixel> imCopy = image;
    

    // TODO
    // variable to check theres only one starting point starting point
    bool validStart = 0;

    //get starting point
    Coordinates start;

    for (int i = 0; i < image.width(); i++)
    {
      for (int j = 0; j < image.height(); j++)
      {
        if(image(i, j) == RED)
        {
          validStart += 1;
          start.rows = i;
          start.cols = j;
        }
      }
    }

    if (!validStart)
    {
      std::cout << "more than one start" << std::endl;
      return EXIT_FAILURE;
    }

    //once start is established, begin BFS

    //queue to traverse image
    Queue<Coordinates, List<Coordinates>> frontier;
    //variable to exit while loop
    bool searching = true; 
    //initial coortinades 
    Coordinates curCoordinates = start;
    //surrounding coordinates
    Coordinates surCoordinates;
    //enqueue starting position
    frontier.enqueue(curCoordinates);

    //check if starting point is goal state
    if (curCoordinates.rows == (image.height() - 1) || curCoordinates.rows == 0  
        || curCoordinates.cols == (image.width() - 1) || curCoordinates.cols == 0)
    {
      image(curCoordinates.rows, curCoordinates.cols) = GREEN;
      // Write solution image to file
      writeToFile(image, output_file);
      return EXIT_SUCCESS;
    }

    //begin while loop
    while(searching)
    {
      //check for solution

      if (curCoordinates.rows == (image.height() - 1) || curCoordinates.rows == 0  
         || curCoordinates.cols == (image.width() - 1) || curCoordinates.cols == 0)
      {
        //set image solution to green
        image(curCoordinates.rows, curCoordinates.cols) = GREEN;
        // Write solution image to file
        writeToFile(image, output_file);
        return EXIT_SUCCESS;        
      }

      //if frontier is empty then there is no solution
      if (frontier.isEmpty())
      {
        return EXIT_SUCCESS;
      }

      //get next state
      frontier.dequeue();

      //previous row
      surCoordinates.rows = curCoordinates.rows - 1;
      surCoordinates.cols = curCoordinates.cols;
      if (imCopy(surCoordinates.rows, surCoordinates.cols) == WHITE)
      {
        frontier.enqueue(surCoordinates);
        imCopy(surCoordinates.rows, surCoordinates.cols) = BLUE;
        //move current coordinates
        curCoordinates = surCoordinates;
      }

      //next row
      surCoordinates.rows = curCoordinates.rows + 1;
      surCoordinates.cols = curCoordinates.cols;
      if (imCopy(surCoordinates.rows, surCoordinates.cols) == WHITE)
      {
        frontier.enqueue(surCoordinates);
        imCopy(surCoordinates.rows, surCoordinates.cols) = BLUE;
        //move current coordinates
        curCoordinates = surCoordinates;   
      } 

      //previous column
      surCoordinates.cols = curCoordinates.cols - 1;
      surCoordinates.rows = curCoordinates.rows;
      if (imCopy(surCoordinates.rows, surCoordinates.cols) == WHITE)
      {
        frontier.enqueue(surCoordinates);
        imCopy(surCoordinates.rows, surCoordinates.cols) = BLUE;
        //move current coordinates
        curCoordinates = surCoordinates;
      }  


      //next column
      surCoordinates.cols = curCoordinates.cols + 1;
      surCoordinates.rows = curCoordinates.rows;
      if (imCopy(surCoordinates.rows, surCoordinates.cols) == WHITE)
      {
        frontier.enqueue(surCoordinates);
        imCopy(surCoordinates.rows, surCoordinates.cols) = BLUE;
        //move current coordinates
        curCoordinates = surCoordinates;  
      } 
    } 
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;

}
