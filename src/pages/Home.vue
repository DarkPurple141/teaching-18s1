<template>
  <section class="content">
     <section-header name="Yo."/>
     <article class="content-body">
        <p>This site is for <em>you</em>. Anything I (Alex Hinds) went over in a tutorial or lab or anything I think might be useful should appear here.
           This is the fifth straight semester I've tutored COMP1511 and the first I've done COMP1521.</p><br>
        <p>If you've got a question please send me an email, or better yet ask it in class.
           This site is enitrely my own and is intended to support and complement the resources already provided on <a href="https://webcms3.cse.unsw.edu.au/">WebCMS3</a>.</p>
     </article>
  </section>
</template>

<script>
import SectionHeader from '@/components/SectionHeader'

export default {
  name: 'Home',
  components: { SectionHeader }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style lang="less" scoped>
@import '../assets/article.less';

</style>
