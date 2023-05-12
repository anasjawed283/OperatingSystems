echo "Enter subject"
read subject
if [ $subject = 'Linux' ]
then
echo "Enter Marks"
read marks
if [ $marks -ge 30 ]
then
echo "You passed"
else
echo "You failed"
fi
else
echo "Wrong Subject"
fi
