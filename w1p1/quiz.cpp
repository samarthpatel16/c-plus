
/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     23-may-2022
------------------------------------------------------------*/



#include "quiz.h"

namespace quizzer
{
    Quiz my_quiz;
    /// <summary>
    /// Loads a quiz from a file.  If a quiz is already loaded, that quiz is discarded
    ///   (together with any information regarding that previously loaded quiz).
    /// </summary>
    /// <param name="filename">The name of the file containing the quiz.</param>
    /// <returns>0 if the quiz was loaded, any other value if some error appeared
    ///   (null parameter, empty parameter, missing file).</returns>
    int LoadQuiz(const char *filename)
    {
        my_quiz = Quiz();
        my_quiz.num_questions = 0;
        my_quiz.score = 0;
        my_quiz.num_questions_asked = 0;

        if (filename == nullptr || filename[0] == '\0')
        {
            return 1;
        }

        ifstream file(filename);
        if (!file.is_open())
        {
            return 2;
        }

        // read file line by line
        string line;
        while (getline(file, line))
        {
            if (line == "" || line == "\n")
            {
                continue;
            }

            int end = line.find(' ');
            string type = line.substr(0, end);
            Question q;
            // if line is a question
            if (type == "{mc}" || type == "{ma}")
            {
                // if quiz is full
                if (my_quiz.num_questions == max_questions)
                {
                    return 3;
                }
                q.type = type;
                q.max_answers_reached = false;
                q.num_answers = 0;
                int start = end + 1;
                q.question = line.substr(start, line.length());

                // read answers
                for (int i = 0; i <= max_answers; i++)
                {

                    getline(file, line);
                    if (line == "" || line == "\n")
                    {
                        break;
                    }
                    if (i == max_answers)
                    {
                        q.max_answers_reached = true;
                        break;
                    }
                    end = line.find(' ');
                    string is_ans = line.substr(0, end);
                    if (is_ans == "[")
                    {
                        line = line.substr(end + 1, line.length());
                        end = line.find(' ');
                    }
                    q.answer[i] = line.substr(end + 1, line.length());
                    if (is_ans == "[X]")
                    {
                        q.correct[i] = true;
                    }
                    q.num_answers++;
                }
            }
            my_quiz.question[my_quiz.num_questions] = q;
            my_quiz.num_questions++;
        }
        return 0;
    }

    int CountCorrectAnswers(Question q)
    {
        int count = 0;
        for (int i = 0; i < q.num_answers; i++)
        {
            if (q.correct[i])
            {
                count++;
            }
        }
        return count;
    }

    /// <summary>
    /// Checks if a quiz is currently loaded and is valid.
    ///   A quiz is considered valid if it has at least 5 questions
    ///   and each question is correct (multiple-choice questions have
    ///   exactly one correct answer, and multiple-answer questions
    ///   have at least one correct answer.
    ///
    ///   For each question in the quiz, print to screen "Question X -> OK" or
    ///   "Question X -> ERROR" if the question is valid or it contains some error.
    ///
    ///   If the quiz has an insufficient number of questions, this function prints nothing.
    /// </summary>
    /// <returns>1 if the quiz is loaded and correct, 0 otherwise</returns>
    int IsQuizValid()
    {
        if (my_quiz.num_questions < 5)
        {
            return 0;
        }
        int is_valid = 1;

        for (int i = 0; i < my_quiz.num_questions; i++)
        {
            Question q = my_quiz.question[i];
            int correct = CountCorrectAnswers(q);
            if (q.type == "{mc}")
            {
                if (correct == 1)
                {
                    cout << "Question " << i+1 << " -> OK" << endl;
                }
                else
                {
                    cout << "Question " << i+1 << " -> ERROR" << endl;
                    is_valid = 0;
                }
            }
            else if (q.type == "{ma}")
            {
                if (correct >= 1)
                {
                    cout << "Question " << i + 1 << " -> OK" << endl;
                }
                else
                {
                    cout << "Question " << i + 1 << " -> ERROR" << endl;
                    is_valid = 0;
                }
            }
        }
        return is_valid;
    }

    /// <summary>
    /// Checks if there are still questions in the quiz that haven't been shown to the user.
    /// </summary>
    /// <returns>1 if the quiz has more questions to show to the user; 0 otherwise.</returns>
    int HasMoreQuestions()
    {
        if (my_quiz.num_questions_asked < my_quiz.num_questions)
        {
            return 1;
        }
        return 0;
    }

    /// <summary>
    /// Prints to the screen the next question from the quiz and records
    ///   user's answer. Once this function is called at least once,
    ///   it is considered that the user took the quiz.
    ///
    /// After the question is shown, this function will print "Your answer? "
    ///   and read the user's choice.
    /// </summary>
    void ShowNextQuestion()
    {
        if (HasMoreQuestions())
        {
            // cout << "QUESTION [" << (my_quiz.num_questions_asked + 1) << "]" << endl;
            // cout << "^^^^^^^^^^^^" << endl;
            Question q = my_quiz.question[my_quiz.num_questions_asked];
            cout << q.question << endl;
            for (int i = 0; i < q.num_answers; i++)
            {
                cout << i + 1 << ". " << q.answer[i] << endl;
            }
            int choice;
            cout << "Your answer? ";
            cin >> choice;
            if (q.type == "{mc}")
            {
                if (q.correct[choice - 1])
                {
                    my_quiz.score++;
                }
            }
            else if (q.type == "{ma}")
            {
                for (int i = 0; i < q.num_answers; i++)
                {
                    if (q.correct[i])
                    {
                        if (choice == i + 1)
                        {
                            my_quiz.score++;
                            break;
                        }
                    }
                }
            }
            my_quiz.num_questions_asked++;
        }
    }

    void ShowQuizResults()
    {
        if (my_quiz.num_questions_asked == my_quiz.num_questions)
        {
            cout << "\nQUIZ RESULTS: your score is " << my_quiz.score << "/" << my_quiz.num_questions <<"."<< endl;
        }
    }
}