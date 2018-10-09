/*
goal:
	classify a sentence to spam or non-spam

Bayes' Theorem:
	p(spam | sentence) = p(sentence | spam) * p(spam) / p(sentence)
	p(non-spam | sentence) = p(sentence | non-spam) * p(non-spam) / p(sentence)

Calculation:
	p(sentence) is the same for two probabilities;
	p(spam) and p(non-spam) are easy to calculate;
	p(sentence | spam) and p(sentence | non-spam) are difficult to calculate.

Naive Bayes Classifier:
	Assume words in sentence are independent, then
	p(sentence | spam) = p(w1 | spam) * p(w2 | spam) * ... * p(wn | spam), and
	p(sentence | non-spam) = p(w1 | non-spam) * p(w2 | non-spam) * ... * p(wn | non-spam).

Calculation:
	p(wi | spam) = #sentence with wi in spam / #sentence in spam
	p(wi | non-spam) = #sentence with wi in non-spam / #sentence in non-spam
*/