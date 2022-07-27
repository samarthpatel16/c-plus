
/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     23-may-2022
------------------------------------------------------------*/




#ifndef quizzer_QUIZ_H
#define quizzer_QUIZ_H
#include <iostream>
#include <string>
#include <fstream>


using namespace std;
namespace quizzer
{
    const int max_answers = 10;
    const int max_questions = 60;
    struct Question
    {
        std::string type;
        std::string question;
        std::string answer[max_answers];
        bool correct[max_answers] = {false};
        int num_answers;
        bool max_answers_reached;
    };

    struct Quiz
    {
        Question question[max_questions];
        int num_questions;
        int score;
        int num_questions_asked;
    };
    

    int LoadQuiz(const char *filename);

    int IsQuizValid();

    int HasMoreQuestions();

    void ShowNextQuestion();

    void ShowQuizResults();

    // Count number of questions asked
    int CountCorrectAnswers(Question q);
}

#endif