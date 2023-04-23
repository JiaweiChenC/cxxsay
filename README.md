

# Instruct GPT vs. GPT 3 vs. Bloomberg GPT

<table id="org91de096" border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">
<caption class="t-above"><span class="table-number">Table 1:</span> Models comparison</caption>

<colgroup>
<col  class="org-left" />

<col  class="org-right" />

<col  class="org-right" />

<col  class="org-left" />
</colgroup>
<thead>
<tr>
<th scope="col" class="org-left">&#xa0;</th>
<th scope="col" class="org-right"># Parameters (billion)</th>
<th scope="col" class="org-right">dataset (billion)</th>
<th scope="col" class="org-left">Training</th>
</tr>
</thead>

<tbody>
<tr>
<td class="org-left"><a href="https://arxiv.org/pdf/2203.02155.pdf">Instruct GPT (ChatGPT)</a></td>
<td class="org-right">175</td>
<td class="org-right">300 &amp; fine-tuning</td>
<td class="org-left">UPT + RLHF</td>
</tr>


<tr>
<td class="org-left"><a href="https://arxiv.org/pdf/2005.14165.pdf">GPT 3</a></td>
<td class="org-right">175</td>
<td class="org-right">300</td>
<td class="org-left">UPT</td>
</tr>


<tr>
<td class="org-left"><a href="https://arxiv.org/pdf/2303.17564.pdf">Bloomberg GPT</a></td>
<td class="org-right">50</td>
<td class="org-right">700</td>
<td class="org-left">UPT</td>
</tr>
</tbody>
</table>

-   UPT: Unsupervised pre-training
-   RLHF: Reinforcement Learning with Human feedback


## Compare GPT3 with Instruct GPT

![img](images/20230422-073812_gpt3vsinstruct.png "GPT 3 vs. Instruct GPT Performance")

-   SFT supervised fine tuning(SFT) model


## Instruct GPT Turning dataset

![img](images/20230422-092710_turning.png "RLHF Turning Dataset")

-   SFT dataset: With labeler demonstrations used to train SFT models
-   RM dataset: labeler rankings of model outputs used to train Reward Model.
-   PPO dataset: Without any human labels with are used as inputs for RLHF fine-tuning.


## Training hardware

-   Bloomberg: 64 &times; 8 A100 GPU, 53 days, 0.8 epoch (only 80% of the dataset)
-   GPT3: Estimated that it cost around $5M in compute time to train GPT-3. Using 1,024x A100 GPUs, researchers calculated that OpenAI could have trained GPT-3 in as little as 34 days. ([ref](https://www.reddit.com/r/GPT3/comments/p1xf10/how_many_days_did_it_take_to_train_gpt3_is/))


# Fine-tuning & RLHF & Alignment

-   Alignment: Generate output aligns with the human intend
-   Fine-tuning: Tune the model structure/parameters to align the pretrained model to
-   RLHF: One of the Fine-tuning techniques

