"""Typing test implementation"""

from utils import *
from ucb import main, interact, trace
from datetime import datetime


###########
# Phase 1 #
###########


def choose(paragraphs, select, k):
    """Return the Kth paragraph from PARAGRAPHS for which SELECT called on the
    paragraph returns true. If there are fewer than K such paragraphs, return
    the empty string.
    """
    fitting = [par for par in paragraphs if select(par)]

    if k >= len(fitting) or len(fitting) == 0:
        return ''
    else:
        return fitting[k]


def about(topic):
    """Return a select function that returns whether a paragraph contains one
    of the words in TOPIC.

    >>> about_dogs = about(['dog', 'dogs', 'pup', 'puppy'])
    >>> choose(['Cute Dog!', 'That is a cat.', 'Nice pup!'], about_dogs, 0)
    'Cute Dog!'
    >>> choose(['Cute Dog!', 'That is a cat.', 'Nice pup.'], about_dogs, 1)
    'Nice pup.'
    """
    assert all([lower(x) == x for x in topic]), 'topics should be lowercase.'

    # initial approach with nested loop,
    # I thought this might be convoluted
    #
    # def check(s):
    #     for word in [remove_punctuation(lower(w)) for w in split(s)]:
    #         for t in topic:
    #             if t == word:
    #                 return True

    #     return False

    def check(s):
        # split into words, then convert to lowercase and remove punctation
        split_undercase = [remove_punctuation(lower(w)) for w in split(s)]

        for t in topic:
            if t in split_undercase:
                return True

        return False

    return check


def accuracy(typed, reference):
    """Return the accuracy (percentage of words typed correctly) of TYPED
    when compared to the prefix of REFERENCE that was typed.

    >>> accuracy('Cute Dog!', 'Cute Dog.')
    50.0
    >>> accuracy('A Cute Dog!', 'Cute Dog.')
    0.0
    >>> accuracy('cute Dog.', 'Cute Dog.')
    50.0
    >>> accuracy('Cute Dog. I say!', 'Cute Dog.')
    50.0
    >>> accuracy('Cute', 'Cute Dog.')
    100.0
    >>> accuracy('', 'Cute Dog.')
    0.0
    """
    if (typed == ''):
        return 0.0

    typed_words = split(typed)
    reference_words = split(reference)

    matches = 0

    for i in range(len(typed_words)):
        if (i < len(reference_words) and typed_words[i] == reference_words[i]):
            matches += 1

    return matches / len(typed_words) * 100


def wpm(typed, elapsed):
    """Return the words-per-minute (WPM) of the TYPED string."""
    assert elapsed > 0, 'Elapsed time must be positive'
    return (len(typed) / 5) / (elapsed / 60)


def autocorrect(user_word, valid_words, diff_function, limit):
    """Returns the element of VALID_WORDS that has the smallest difference
    from USER_WORD. Instead returns USER_WORD if that difference is greater
    than LIMIT.
    """
    if user_word in valid_words:
        return user_word

    result = min(valid_words, key=lambda w: diff_function(user_word, w, limit))

    if diff_function(user_word, result, limit) <= limit:
        return result
    else:
        return user_word


def swap_diff(start, goal, limit):
    """A diff function for autocorrect that determines how many letters
    in START need to be substituted to create GOAL, then adds the difference in
    their lengths.
    """
    # n – number of substitutions so far
    def substitute(s1, s2, n):
        if n > limit:
            return n + 1

        elif len(s1) == 0 or len(s2) == 0:
            return n

        elif len(s1) > len(s2):
            length_diff = abs(len(s2) - len(s1))
            return substitute(s1[:-length_diff], s2, n + length_diff)

        elif len(s1) < len(s2):
            length_diff = abs(len(s2) - len(s1))
            return substitute(s1, s2[:-length_diff], n + length_diff)

        elif s1[0] == s2[0]:
            return substitute(s1[1:], s2[1:], n)

        else:
            return substitute(s1[1:], s2[1:], n + 1)

    return substitute(start, goal, 0)


def edit_diff(start, goal, limit):
    """A diff function that computes the edit distance from START to GOAL."""
    if limit < 0:
        return 1
    elif start == goal:
        return 0
    elif len(start) == 0 or len(goal) == 0:
        return max(len(start), len(goal))
    else:
        diff = start[0] != goal[0]
        add_diff = 1 + edit_diff(start, goal[1:], limit-1)
        remove_diff = 1 + edit_diff(start[1:], goal, limit-1)
        substitute_diff = diff + edit_diff(start[1:], goal[1:], limit-diff)
    return min(add_diff, remove_diff, substitute_diff)


def final_diff(start, goal, limit):
    """A diff function. If you implement this function, it will be used."""
    assert False, 'Remove this line to use your final_diff function'


###########
# Phase 3 #
###########


def report_progress(typed, prompt, id, send):
    """Send a report of your id and progress so far to the multiplayer server."""
    def match_count(s1, s2):
        if (len(s1) == 0 or len(s2) == 0):
            return 0
        if s1[0] != s2[0]:
            return 0
        else:
            return 1 + match_count(s1[1:], s2[1:])

    progress = match_count(typed, prompt) / len(prompt)
    send({'id': id, 'progress': progress})
    return progress


def fastest_words_report(word_times):
    """Return a text description of the fastest words typed by each player."""
    fastest = fastest_words(word_times)
    report = ''
    for i in range(len(fastest)):
        words = ','.join(fastest[i])
        report += 'Player {} typed these fastest: {}\n'.format(i + 1, words)
    return report


def fastest_words(word_times, margin=1e-5):
    """A list of which words each player typed fastest."""
    n_players = len(word_times)
    n_words = len(word_times[0]) - 1
    assert all(len(times) == n_words + 1 for times in word_times)
    assert margin > 0
    # [print(word(w)) for w in word_times[0]]
    # for p in word_times:
    total_elapsed_time = []
    results = []

    for p in word_times:
        total_elapsed_time.append([elapsed_time(p[i]) - elapsed_time(p[i - 1])
                                   for i in range(1, n_words + 1)])
        results.append([])

    words = [word(p) for p in word_times[0]][1:]
    for i in range(len(words)):
        times = [t[i] for t in [times for times in total_elapsed_time]]
        fastest = min(times)
        for j in range(len(times)):
            if fastest + margin >= times[j]:
                results[j].append(words[i])

    return results


def word_time(word, elapsed_time):
    """A data abstrction for the elapsed time that a player finished a word."""
    return [word, elapsed_time]


def word(word_time):
    """An accessor function for the word of a word_time."""
    return word_time[0]


def elapsed_time(word_time):
    """An accessor function for the elapsed time of a word_time."""
    return word_time[1]


p0 = [word_time('START', 0), word_time('What', 0.2),
      word_time('great', 0.4), word_time('luck', 0.8)]
p1 = [word_time('START', 0), word_time('What', 0.6),
      word_time('great', 0.8), word_time('luck', 1.19)]
fastest_words([p0, p1])

enable_multiplayer = False  # Change to True when you


##########################
# Command Line Interface #
##########################


def run_typing_test(topics):
    """Measure typing speed and accuracy on the command line."""
    paragraphs = lines_from_file('data/sample_paragraphs.txt')
    def select(p): return True
    if topics:
        select = about(topics)
    i = 0
    while True:
        reference = choose(paragraphs, select, i)
        if not reference:
            print('No more paragraphs about', topics, 'are available.')
            return
        print('Type the following paragraph and then press enter/return.')
        print('If you only type part of it, you will be scored only on that part.\n')
        print(reference)
        print()

        start = datetime.now()
        typed = input()
        if not typed:
            print('Goodbye.')
            return
        print()

        elapsed = (datetime.now() - start).total_seconds()
        print("Nice work!")
        print('Words per minute:', wpm(typed, elapsed))
        print('Accuracy:        ', accuracy(typed, reference))

        print('\nPress enter/return for the next paragraph or type q to quit.')
        if input().strip() == 'q':
            return
        i += 1


@main
def run(*args):
    """Read in the command-line argument and calls corresponding functions."""
    import argparse
    parser = argparse.ArgumentParser(description="Typing Test")
    parser.add_argument('topic', help="Topic word", nargs='*')
    parser.add_argument('-t', help="Run typing test", action='store_true')

    args = parser.parse_args()
    if args.t:
        run_typing_test(args.topic)
