#!/bin/bash

read -p "(alpha, #topics) = " alpha num_topic

read -p "Number of review to be viewed = " num_review

echo -e "Generating topics"
LDA/lda-c-dist/lda est $alpha $num_topic LDA/lda-c-dist/settings.txt Util/VocabExtract/ap.dat random ../result

echo -e "Removing newdb.db"
rm ../yelp_dataset.db

echo -e "Generating DB"
python Util/tmve-read-only/lib/generate_db.py ../yelp_dataset.db Util/VocabExtract/ap.dat ../result/final.beta ../result/final.gamma Util/VocabExtract/vocab.txt ../dataset/yelp_academic_dataset_review.json $num_review

exit 0
